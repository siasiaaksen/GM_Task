#pragma once


typedef int DataType;

// �ߴ����̳� ������Ҷ� �׳� �ڷ����� 
// ������ �ִ°��� ���Ⱑ �� ���ؼ� �̹���� ���� ����ߴ�.
// template<typename DataType>
class UList
{
public:
    class UListNode
    {
        // friend UList;
        // friend iterator;

    public:
        UListNode* Prev = nullptr;
        UListNode* Next = nullptr;
        DataType Data;
    };

public:
    // ��ȸ�ڶ�� Ŭ������ ���ؼ� 
    class iterator
    {
    public:
    private:
        UListNode* CurNode;
    };

public:
    UList()
    {
        // ���̳���� �մϴ�.
        Start = new UListNode();
        End = new UListNode();
        Start->Data = -1;
        End->Data = -1;

        Start->Next = End;
        End->Prev = Start;
    }

    ~UList()
    {

    }

    // push_back�� �������Լ�
    void push_front(const DataType& _Data)
    {
        UListNode* ListNode = new UListNode();
        ListNode->Data = _Data;

        ListNode->Prev = Start;
        ListNode->Next = Start->Next;

        // �̳༮�� ���� �Ǹ� 
        Start->Next->Prev = ListNode;
        Start->Next = ListNode;
    }

    void push_back(const DataType& _Data)
    {
        UListNode* ListNode = new UListNode();
        ListNode->Data = _Data;

        ListNode->Next = End;
        ListNode->Prev = End->Prev;

        // �̳༮�� ���� �Ǹ� 
        End->Prev->Next = ListNode;
        End->Prev = ListNode;

    }


private:
    UListNode* Start = nullptr;
    UListNode* End = nullptr;

};

