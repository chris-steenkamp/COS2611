#include <iostream>

using namespace std;

struct NodeType
{
    int info;
    NodeType *link;
};

NodeType* createList();

NodeType* testList();

void traverse(NodeType *);

void addToList(NodeType* &list, int value);

NodeType *getLastNode(NodeType *list);

int main()
{
    char read;
    NodeType *list = testList();
    NodeType *A = list->link;
    NodeType *B = A->link->link->link->link;

    A = A->link;

    list = list->link->link->link;

    while (B->link)
        B = B->link;

    A = list;
    delete list;
    list = NULL;

    cout << "list:" << endl;
    traverse(list);

    cout << "A:" <<endl;
    traverse(A);

    cout << "B:" <<endl;
    traverse(B);

    delete list;
    list = NULL;

    delete B;
    B = NULL;
    return 0;
}

NodeType *getLastNode(NodeType *list)
{
    while (list != NULL && list->link != NULL)
    {
        list = list->link;
    }

    return list;
}

NodeType* testList()
{
    NodeType *list = NULL;

    addToList(list, 18);
    addToList(list, 32);
    addToList(list, 23);
    addToList(list, 16);
    addToList(list, 43);
    addToList(list, 87);
    addToList(list, 25);
    addToList(list, 44);

    return list;
}

NodeType* createList()
{
    NodeType *list = NULL;

    int value;

    while (value != -1)
    {
        cout << "Enter value (-1 to exit): ";
        cin >> value;

        if (value > -1)
        {
            addToList(list, value);
        }
    }

    return list;
}

void traverse(NodeType *list)
{
    NodeType *current = list;
    int i = 0;

    while (current != NULL)
    {
        cout << "Item " << i++ << " = " << current->info << endl;
        current = current->link;
    }
}

void addToList(NodeType* &list, int value)
{
    NodeType *newNode = NULL, *lastNode = getLastNode(list);

    newNode = new NodeType;
    newNode->info = value;
    newNode->link = NULL;

    if (list == NULL)
    {
        list = newNode;
        lastNode = newNode;
    }
    else
    {
        lastNode->link = newNode;
        lastNode = newNode;
    }
}
