#include "Player.h"
#include <conio.h>
#include "Enums.h"
#include "GlobalValue.h"
#include "ConsoleEngine.h"

void Player::BeginPlay()
{
	PlayerImage.Create({1, 1}, '@');
}

void Player::Tick(ConsoleImage* _BackBuffer)
{
	// ConsoleImage& BackBuffer = *_BackBuffer;

	// static은 전역이니까 객체가 필요없다.
	ConsoleEngine::GetWindow();
	ConsoleEngine::GetWindowSize();

	// 남에 코드 안건드리고 
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
		default:
			break;
		}

	}

	switch (Dir)
	{
	case Enums::GAMEDIR::LEFT:
		Pos += FIntPoint::LEFT;
		break;
	case Enums::GAMEDIR::RIGHT:
		Pos += FIntPoint::RIGHT;
		break;
	case Enums::GAMEDIR::UP:
		Pos += FIntPoint::UP;
		break;
	case Enums::GAMEDIR::DOWN:
		Pos += FIntPoint::DOWN;
		break;
	default:
		break;
	}
}

void Player::Render(ConsoleImage* _BackBuffer)
{
	// delete _BackBuffer;
	_BackBuffer->Copy(Pos, PlayerImage);
}

void Player::SetActorLocation(FIntPoint _Pos)
{
	Pos = _Pos;
}