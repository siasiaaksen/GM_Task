#pragma once
#include "ConsoleImage.h"
#include "Actor.h"

//class AActor
//{
//	FIntPoint Location;
//};
//
//class Monster
//{
//	
//};

// ȭ���򰡿� �̳༮�� ������
// �Ϲ����� ���ӿ���
class Player : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

private:
};

