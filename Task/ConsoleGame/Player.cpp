#include "Player.h"
#include <conio.h>
#include "Enums.h"
#include "GlobalValue.h"
#include "ConsoleEngine.h"
#include "Renderer.h"

Player* Player::MainPlayer = nullptr;

void Player::BeginPlay()
{
	// �� 1�� ��������� �÷��̾ static �����ǰ� �˴ϴ�.
	MainPlayer = this;

	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');

	// 1. ������ �Ʒ� ��ġ�� ���ƴ޶�.
	SetActorLocation({ 10, 8 });
}

void Player::Tick()
{
	Super::Tick();
	// ConsoleEngine::MainPlayer

	// Ÿ���� ���� �ҷ��� ���.
	// ConsoleEngine::GetEngine().GetPlayer()

	// ConsoleImage& BackBuffer = *_BackBuffer;

	// static�� �����̴ϱ� ��ü�� �ʿ����.
	ConsoleEngine::GetWindow();
	ConsoleEngine::GetWindowSize();

	// ���� �ڵ� �Ȱǵ帮�� 
	GlobalValue::WindowPtr;
	GlobalValue::WindowSize;

	

	int Value = _kbhit();
	Enums::GAMEDIR Dir = Enums::GAMEDIR::NONE;
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			Dir = Enums::GAMEDIR::LEFT;
			break;
		case 'D':
		case 'd':
			Dir = Enums::GAMEDIR::RIGHT;
			break;
		case 'W':
		case 'w':
			Dir = Enums::GAMEDIR::UP;
			break;
		case 'S':
		case 's':
			Dir = Enums::GAMEDIR::DOWN;
			break;
		case 'Z':
		case 'z':
		{
			Bullet* NewBullet = ConsoleEngine::GetEngine().SpawnActor<Bullet>();

			// 1. �Ѿ��� �÷��̾� ��ġ�� ������ ���弼��
			// 2. �Ѿ��� �������� �ö󰡰� ���弼��.
			NewBullet->SetActorLocation(this->GetActorLocation());

			// �����ϴ��ڰ� ������?
			// ���� ������ AllActorVector ���� ������ �ִ�.
			// �÷��̾ ���� ������ ���α׷��Ӱ� BulletVector�� ����� ���⿡�� �־����.
			// 
			// �÷��̾ �Ѿ��� �Ŵ�����Ʈ 
			BulletVector.push_back(NewBullet);
			// delete NewBullet;

			break;
		}
		default:
			break;
		}

	}

	switch (Dir)
	{
	case Enums::GAMEDIR::LEFT:
		AddActorLocation(FIntPoint::LEFT);
		break;
	case Enums::GAMEDIR::RIGHT:
		AddActorLocation(FIntPoint::RIGHT);
		break;
	case Enums::GAMEDIR::UP:
		AddActorLocation(FIntPoint::UP);
		break;
	case Enums::GAMEDIR::DOWN:
		AddActorLocation(FIntPoint::DOWN);
		break;
	default:
		break;
	}

	// Pos += FIntPoint::RIGHT;
}

