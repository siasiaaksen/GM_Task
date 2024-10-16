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

	void RenderMemory(FIntPoint _Pos);

private:
	Renderer* Render = nullptr;
	static Memory* memory;

	static int Value;
};

