#include <conio.h>

#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/Renderer.h>

#include "Block.h"
#include "Memory.h"


void Block::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, 'B');
}

void Block::Tick()
{
	Super::Tick();

	Memory* memory = Memory::GetMemory();

	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			AddActorLocation(FIntPoint::LEFT);
			break;
		case 'D':
		case 'd':
			AddActorLocation(FIntPoint::RIGHT);
			break;
		case 'W':
		case 'w':
			AddActorLocation(FIntPoint::UP);
			break;
		case 'S':
		case 's':
			AddActorLocation(FIntPoint::DOWN);
			break;
		case 'T':
		case 't':
			//AddActorLocation(FIntPoint::DOWN);
			memory->RenderMemory(this->GetActorLocation());
			break;
		default:
			break;
		}
	}
}