#include <conio.h>

#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/Renderer.h>

#include "Block.h"


void Block::BeginPlay()
{
	Super::BeginPlay();

	BackBuffer = ConsoleEngine::GetEngine().GetWindow()->GetBackBufferPtr();
	memory = Memory::GetMemory();


	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, 'B');

	FIntPoint BBSize = BackBuffer->GetImageSize();
	FIntPoint BlockPos = this->GetActorLocation();

}

void Block::Tick()
{
	Super::Tick();

	Move();
	BlockCheck();
}

void Block::Move()
{
	int Value = _kbhit();

	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			if (0 == this->GetActorLocation().X)
			{
				return;
			}
			AddActorLocation(FIntPoint::LEFT);
			break;
		case 'D':
		case 'd':
			if (BackBuffer->GetImageSize().X - 1 == this->GetActorLocation().X)
			{
				return;
			}
			AddActorLocation(FIntPoint::RIGHT);
			break;
		case 'W':
		case 'w':
			if (0 == this->GetActorLocation().Y)
			{
				return;
			}
			AddActorLocation(FIntPoint::UP);
			break;
		case 'S':
		case 's':
			if (BackBuffer->GetImageSize().Y - 1 == this->GetActorLocation().Y)
			{
				return;
			}
			AddActorLocation(FIntPoint::DOWN);
			break;
		default:
			break;
		}
	}
}

void Block::BlockCheck()
{
	FIntPoint CurPos = GetActorLocation();
	FIntPoint DownPos = CurPos + FIntPoint::DOWN;

	char DownImage = memory->GetRenderer()->RenderImage.GetPixel(DownPos.X, DownPos.Y);

	if (BackBuffer->GetImageSize().Y - 1 == CurPos.Y)
	{
		memory->RenderMemory(CurPos);
		this->SetActorLocation({ 0, -1 });
	}
	else if ('B' == DownImage)
	{
		memory->RenderMemory(CurPos);
		this->SetActorLocation({ 0, -1 });

	}
}