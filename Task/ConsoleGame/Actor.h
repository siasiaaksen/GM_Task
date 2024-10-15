#pragma once
#include <BaseSystem/EngineMath.h>
#include "ConsoleImage.h"


class AActor
{
	

public:
	virtual void BeginPlay();
	virtual void Tick();

	void Render(ConsoleImage* _BackBuffer);

	void SetActorLocation(FIntPoint _Pos);

	void AddActorLocation(FIntPoint _Pos);

	FIntPoint GetActorLocation()
	{
		return Pos;
	}

	class Renderer* CreateDefaultSubObject();


protected:
	// ConsoleImage RenderImage;
	// �������� ����� ����.
	// �׷����� �ϸ� �������� �����
	// �ȱ׷������ϸ� �ȸ���� �ȴ�.

private:
	class Renderer* ImageRenderer;
	FIntPoint Pos;
	// �����Ҵ� �Ұų� ���ų�?
};

typedef AActor Super;