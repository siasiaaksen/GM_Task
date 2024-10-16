#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>

#include "Memory.h"

class Block : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;
	void Move();
	void BlockCheck();

private:
	ConsoleImage* BackBuffer = nullptr;
	Memory* memory = nullptr;
};

