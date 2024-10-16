#include "TetrisInit.h"
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>

#include "Block.h"
#include "Memory.h"


void TetrisInit::UserBeginPlay(ConsoleEngine* _MainEngine)
{
	// ������ �մϴ�.
	_MainEngine->GetWindow()->SetScreenSize({3, 5});
	_MainEngine->SpawnActor<Memory>();
	_MainEngine->SpawnActor<Block>();
}