#pragma once
#include "Actor.h"

class Monster : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	// 이방식의 문제는?
	// 플레이어가 
	// Player* NewPlayer = nullptr;
};

