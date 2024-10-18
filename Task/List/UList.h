#pragma once
#include <assert.h>

//typedef int DataType;
template<typename DataType>
class UList
{
public:
    class UListNode
    {
    public:
        UListNode* Prev = nullptr;
        UListNode* Next = nullptr;
        DataType Data;

    public:
        // 재귀함수2
        void Release()
        {
            if (nullptr != Next)
            {
                Next->Release();
            }

            delete this;
        }
    };

public:
    class iterator
    {
        friend UList;

    public:
        iterator()
        {

        }

        bool operator!=(const iterator& _Other)
        {
            return CurNode != _Other.CurNode;
        }

        DataType& operator*()
        {
            return CurNode->Data;
        }

        iterator& operator++()
        {
            CurNode = CurNode->Next;
            return *this;
        }

        DataType& GetValue()
        {
            return CurNode->Data;
        }

    private:
        iterator(UListNode* _Node)
            : CurNode(_Node)
        {

        }

        UListNode* CurNode = nullptr;
    };

public:
    UList()
    {
        StartNode = new UListNode();
        EndNode = new UListNode();
        StartNode->Data = -1;
        EndNode->Data = -1;

        StartNode->Next = EndNode;
        EndNode->Prev = StartNode;
    }

    ~UList()
    {
        // 재귀방식2
        StartNode->Release();


        // 재귀방식1
        //ReDelete(StartNode);


        // while 방식
        //{
        //    clear();

        //    if (nullptr != StartNode)
        //    {
        //        delete StartNode;
        //        StartNode = nullptr;
        //    }

        //    if (nullptr != EndNode)
        //    {
        //        delete EndNode;
        //        EndNode = nullptr;
        //    }
        //}
    }

    // while 방식
    void clear()
    {
        UListNode* CurNode = StartNode->Next;

        while (EndNode != CurNode)
        {
            UListNode* NextNode = CurNode->Next;
            if (nullptr != CurNode)
            {
                delete CurNode;
                CurNode = nullptr;
            }

            CurNode = NextNode;
        }
    }

    // 재귀방식1(StartNode, EndNode 다 지우는)
    void ReDelete(UListNode* _Node)
    {
        if (nullptr == _Node->Next)
        {
            delete _Node;
            _Node = nullptr;
            return;
        }

        ReDelete(_Node->Next);
        delete _Node;
        _Node = nullptr;
    }

    void push_front(const DataType& _Data)
    {
        UListNode* ListNode = new UListNode();
        ListNode->Data = _Data;

        ListNode->Prev = StartNode;
        ListNode->Next = StartNode->Next;

        StartNode->Next->Prev = ListNode;
        StartNode->Next = ListNode;
    }

    void push_back(const DataType& _Data)
    {
        UListNode* ListNode = new UListNode();
        ListNode->Data = _Data;

        ListNode->Next = EndNode;
        ListNode->Prev = EndNode->Prev;

        EndNode->Prev->Next = ListNode;
        EndNode->Prev = ListNode;
    }

    iterator erase(iterator& _Data)
    {
        UListNode* CurNode = _Data.CurNode;
        if (CurNode == nullptr)
        {
            assert(false);
            return iterator();
        }

        if (CurNode == StartNode)
        {
            assert(false);
            return iterator();
        }

        if (CurNode == EndNode)
        {
            assert(false);
            return iterator();
        }

        UListNode* ReturnNode = CurNode->Next;

        CurNode->Prev->Next = CurNode->Next;
        CurNode->Next->Prev = CurNode->Prev;

        delete CurNode;
        CurNode = nullptr;

        return iterator(ReturnNode);
    }

    iterator begin() 
    {
        return iterator(StartNode->Next);
    }

    iterator end()
    {
        return iterator(EndNode);
    }


private:
    UListNode* StartNode = nullptr;
    UListNode* EndNode = nullptr;
};

