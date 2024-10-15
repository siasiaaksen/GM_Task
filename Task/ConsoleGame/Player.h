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

// 화면어딘가에 이녀석이 랜더링
// 일반적인 게임엔진
class Player : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	// 플레이어가 여러개 만들어지지 않을 것이다.
	// 플레이어는 이게임에서 딱 1개 만들어질것이다.
	static Player* GetMainPlayer()
	{
		return MainPlayer;
	}

	// 이방식은 좋지 않다.
	// 레퍼런스로 리턴하고 싶다면
	// const 리턴해야 한다.
	// 보기만 해라. 수정하지 말고.
	const ActorVector& GetBulletVector()
	{
		return BulletVector;
	}


private:
	static Player* MainPlayer;
	// 또다른 리스트를 가지게 한다.
	ActorVector BulletVector;
};

