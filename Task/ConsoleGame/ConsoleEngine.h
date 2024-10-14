#pragma once
#include "ConsoleWindow.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ActorVector.h"

class ConsoleEngine
{
	// void Update(); // �����δ�.
	// void Move(); // �����δ�.
public:
	static void Start();

	static FIntPoint GetWindowSize()
	{
		return WindowSize;
	}

	static UConsoleWindow& GetWindow()
	{
		return Window;
	}

	static ConsoleEngine& GetEngine()
	{
		return *MainEngine;
	}

	template<typename ActorType>
	ActorType* SpawnActor()
	{
		ActorType* NewActor = new ActorType();
		AllActorVector.push_back(NewActor);
		// ����÷��̵� ���⼭ ��������ش�.
		NewActor->BeginPlay();
		return NewActor;
	}

	//AActor* SpawnBullet()
	//{
	//	Bullet* NewActor = new Bullet();

	//	AllActorVector.push_back(NewActor);
	//	return NewActor;
	//}

	//AActor* SpawnMonster()
	//{
	//	Monster* NewActor = new Monster();

	//	AllActorVector.push_back(NewActor);
	//	return NewActor;
	//}

	// �̰� �������� ���� �̱����̴�.
	// �̳��� �̱����� ���������� ���� �������
	// �̱����� �ٽ� => ���α׷����� �� 1���� ��ü�� �����.
	//                 ��� ������ ����.
	//                 ���α׷������� ��� Ŭ������ ��� 
	//                 ��ü�� �� 1���� ����� �����ϴ� ���.
	
	//static ConsoleEngine* Inst;
	//ConsoleEngine* GetInst()
	//{
	//	if (nullptr == Inst)
	//	{
	//		Inst = new ConsoleEngine();
	//	}
	//	return Inst;
	//}

private:
	// �����ڸ� ���Ҿ�.
	ConsoleEngine();

	// ���� �ְ� ��ü�� �������� �ʱ� ������
	// �ܺα�ȣ ������ ���.
	// ���α׷��� ����ɶ����� �ı����� �ʽ��ϴ�.
	static FIntPoint WindowSize;
	static UConsoleWindow Window;

	static ConsoleEngine* MainEngine;

	// ȭ�鿡 ������ ��� Actor�� ��Ƽ� ������ ��1���� �ڷᱸ���� �����Ѵ�.
	ActorVector AllActorVector;

	void BeginPlay(); // �����δ�.
	void Tick(); // �����δ�.
	void Render(); // �׸���.
};

