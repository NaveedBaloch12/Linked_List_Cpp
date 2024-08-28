#include <iostream>

using namespace std;

// 1D Node
class Node
{
public:
    int Data;
    Node *next;

    Node(int data)
    {
        Data = data;
        next = NULL;
    }
    Node()
    {
    }
};

Node *CreateNode(int data)
{
    Node *newNode = new Node();
    newNode->Data = data;
    newNode->next = NULL;
    return newNode;
}

void PrintList(Node *Head)
{
    Node *ptr = Head;
    while (ptr != NULL)
    {
        cout << ptr->Data << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}

int CountNodes(Node *Head)
{
    int count = 0;
    Node *ptr = Head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

Node *InsertAtBegin(Node *Head, int Data)
{
    Node *newNode = CreateNode(Data);
    newNode->next = Head;
    Head = newNode;
    return Head;
}

Node *InsertAtEnd(Node *Head, int Data)
{
    Node *newNode = CreateNode(Data);
    Node *ptr = Head;
    if (ptr == NULL)
    {
        Head = newNode;
        return Head;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return Head;
}

Node *InsertAtPosition(Node *Head, int Data, int pos)
{
    if (pos > 0 && pos <= CountNodes(Head))
    {
        Node *newNode = CreateNode(Data);
        Node *ptr = Head;
        for (int i = 1; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }

        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    else
    {
        cout << "Invalid position" << endl;
    }
    return Head;
}

Node *DeleteNodeAtBegin(Node *Head)
{
    if (Head == NULL)
    {
        cout << "List is empty. Cannot delete node." << endl;
        return Head;
    }
    Node *temp = Head->next;
    delete Head;

    return temp;
}

Node *DeleteNodeAtEnd(Node *Head)
{
    if (Head == NULL)
    {
        cout << "List is empty. Cannot delete node." << endl;
        return Head;
    }
    Node *ptr = Head;
    Node *prev = NULL;
    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    delete ptr;
    prev->next = NULL;
    return Head;
}

Node *DeleteAtPostion(Node *Head, int postion)
{
    if (postion >= 0 && postion < CountNodes(Head))
    {
        Node *ptr = Head;
        Node *prev = NULL;
        for (int i = 1; i < postion; i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
    }
    return Head;
}

Node* ReverceList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *Prev = head;
    Node *Curr = head->next;
    Node *Next = head->next->next;

    while(Curr != NULL)
    {
        Curr->next = Prev;

        Prev = Curr;
        Curr = Next;
        if(Next != NULL)
            Next = Next->next;
    }
    head->next = NULL;
    return Prev;
}

// One Ptr Method
bool DetectCircularList(Node *head)
{
    Node *ptr = head;
    while(ptr != NULL)
    {
        if(ptr->next == head)
            return true;
        ptr = ptr->next;
    }
    return false;
}


int main()
{
    Node *Head = new Node(0);
    // // Insert a new node in front of the head
    // for(int i = 9 ; i > 0 ; i--)
    // {
    //     Head = InsertAtBegin(Head, i);
    // }

    // // Insert a new node at the end
    // for(int i = 11; i <= 20; i++)
    // {
    //     Head = InsertAtEnd(Head, i);
    // }

    // // Insert a new node at a given position
    // Head = InsertAtPosition(Head, 50, 11);

    for (int i = 1; i < 20; i++)
    {
        Head = InsertAtEnd(Head, i);
    }
    PrintList(Head);
    cout << "Number of Nodes are: " << CountNodes(Head) << endl;

    // Head = DeleteAtPostion(Head, 4);
    // PrintList(Head);
    // cout << "Number of Nodes are: " << CountNodes(Head) << endl;

    Head = ReverceList(Head);
    PrintList(Head);

    return 0;
}