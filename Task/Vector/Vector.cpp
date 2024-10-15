#include <iostream>
#include <vector>
#include "UVector.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 공간을 나타내는 capacity() => 배열의크기
    // 자료를 나내트는 size() => 배열에 들어간 자료의 크기

    {
        std::vector<int> stdvector;

        stdvector.reserve(100);
        stdvector.reserve(10);

        for (int i = 0; i < 10; i++)
        {
            // 0개
            // capacity가 먼저 늘어난다.
            // i가 늘어난 공간에 추가되죠.
            // size도 늘어난다.
            stdvector.push_back(i);
            std::cout << "push : " << stdvector[i] << std::endl;
            std::cout << "capacity : " << stdvector.capacity() << std::endl;
            std::cout << "size     : " << stdvector.size() << std::endl;
        }

        stdvector.clear();

        std::cout << "claer after capacity : " << stdvector.capacity() << std::endl;
    }


    {
        UVector<int> stdvector;
        stdvector.reserve(10);

        for (int i = 0; i < 10; i++)
        {
            stdvector.push_back(i);
            std::cout << "push : " << stdvector[i] << std::endl;
            std::cout << "capacity : " << stdvector.capacity() << std::endl;
            std::cout << "size     : " << stdvector.size() << std::endl;
        }

        stdvector.clear();
    }
}
