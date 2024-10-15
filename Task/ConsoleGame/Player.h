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

	// �÷��̾ ������ ��������� ���� ���̴�.
	// �÷��̾�� �̰��ӿ��� �� 1�� ����������̴�.
	static Player* GetMainPlayer()
	{
		return MainPlayer;
	}

	// �̹���� ���� �ʴ�.
	// ���۷����� �����ϰ� �ʹٸ�
	// const �����ؾ� �Ѵ�.
	// ���⸸ �ض�. �������� ����.
	const ActorVector& GetBulletVector()
	{
		return BulletVector;
	}


private:
	static Player* MainPlayer;
	// �Ǵٸ� ����Ʈ�� ������ �Ѵ�.
	ActorVector BulletVector;
};

