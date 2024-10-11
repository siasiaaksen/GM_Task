#pragma once
#include "ConsoleWindow.h"
#include "Player.h"

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

private:
	ConsoleEngine();

	// ���� �ְ� ��ü�� �������� �ʱ� ������
	// �ܺα�ȣ ������ ���.
	static FIntPoint WindowSize;
	static UConsoleWindow Window;

	Player NewPlayer;

	// 2�� ������� �ʽ��ϴ�.
	void BeginPlay(); // �����δ�.

	void Tick(); // �����δ�.
	void Render(); // �׸���.
};

