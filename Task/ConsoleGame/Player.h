#pragma once
#include "ConsoleImage.h"
#include "Actor.h"
#include "ActorVector.h"

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
	// �Ǵٸ� ����Ʈ�� ������ �Ѵ�.
	ActorVector BulletVector;
	static Player* MainPlayer;

};

