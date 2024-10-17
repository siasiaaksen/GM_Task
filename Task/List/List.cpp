#include <iostream>
#include <list>
#include "UList.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {
        //std::list<int> Newint;
        //Newint.push_front(9);
        //Newint.push_back(0);
        //Newint.push_back(1);
        //Newint.push_back(2);
        //Newint.push_back(3);

        //std::list<int>::iterator TestIter = Newint.end();

        //std::list<int>::iterator StartIter = Newint.begin();
        //std::list<int>::iterator EndIter = Newint.end();

    }
    
    {
        // 1. 릭 없애기 
        // 2. push_front 만들기

        UList<int> Newint;
        Newint.push_back(0);
        Newint.push_back(1);
        Newint.push_back(2);
        Newint.push_back(3);
        Newint.push_front(9);


        UList<int>::iterator TestIter = Newint.begin();
        //++TestIter;
        TestIter = Newint.erase(TestIter);

        int a = 0;

        UList<int>::iterator BeginIter = Newint.begin();
        UList<int>::iterator EndIter = Newint.end();
        for (; BeginIter != EndIter; ++BeginIter)
        {
            int& Value = *BeginIter;
            std::cout << Value << std::endl;
        }
    }
}
