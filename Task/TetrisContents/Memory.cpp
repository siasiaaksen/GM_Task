#include "Memory.h"
#include <EngineCore/Renderer.h>

Memory* Memory::memory;

void Memory::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 3, 5 }, 'o');

	//Render->RenderImage.SetPixel({0, 4}, 'B');
	//Render->RenderImage.SetPixel({ 1, 4 }, 'B');
	//Render->RenderImage.SetPixel({ 2, 4 }, 'B');
}

void Memory::Tick()
{
	Super::Tick();
}

