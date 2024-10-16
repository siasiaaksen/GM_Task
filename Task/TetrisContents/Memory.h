#pragma once
#include <EngineCore/Actor.h>

class Memory : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	static Memory* GetMemory()
	{
		return memory;
	}

private:
	static Memory* memory;
};

