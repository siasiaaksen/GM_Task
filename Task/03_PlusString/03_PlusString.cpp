// 003_PlusString.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void PlusString(char* _Buffer, int _BufferSize, const char* const _Value0, const char* const _Value1)
{
    int Value0Count = strlen(_Value0);
    int Value1Count = strlen(_Value1);

    for (int i = 0; i < Value0Count; i++)
    {
        _Buffer[i] = _Value0[i];
    }

    for (int i = 0; i < Value1Count; i++)
    {
        _Buffer[i + Value0Count] = _Value1[i];
    }

    return;
}

int main()
{
    char Arr[100] = {};

    PlusString(Arr, 100, "AAAA", "BBBB");
}

