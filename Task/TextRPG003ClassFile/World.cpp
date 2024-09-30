#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include <conio.h>


void UWorld::InPlayer(class UPlayer& _Player)
{
	char InputName[100] = { 0, };

	bool IsNameInput = true;

	while (true)
	{
		if (true == IsNameInput)
		{
			system("cls");

			std::cout << "�̸��� �����ּ���" << std::endl;
			std::cin >> InputName;
		}
		
		system("cls");
		printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
		printf_s("a. ����\n");
		printf_s("b. ���Է�\n");
		int Select = _getch();
		bool IsEnd = false;
		switch (Select)
		{
		case 'a':
		case 'A':
			IsNameInput = false;
			IsEnd = true;
			break;
		case 'b':
		case 'B':
			IsNameInput = true;
			IsEnd = false;
			break;
		default:
			IsNameInput = false;
			IsEnd = false;
			printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n", InputName);
			_getch();
			break;
		}

		if (true == IsEnd)
		{
			break;
		}
	}

	// �������ʱ��� ���⼭ �� ������� ����
	// ������ ������ FightZone�� ��� �ȴ�.
	// ���� ��� �������� 

	// new�� �� ����� �ϴ°ų�?
	// 8�Ⱑ
	UTown TownZone;
	TownZone.SetName("�ʺ�����");

	// 10�Ⱑ
	UFightZone FightZone;
	FightZone.SetName("�ʺ������");

	while (true)
	{
		TownZone.InPlayer(_Player);
	}



}