#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void print(Node* temp)
    {
        if (temp == NULL)
        {
            cout << endl;
            return;
        }

        cout << temp->data << " ";

        print(temp->next);
    }

    void display()
    {
        print(head);
    }

    void insertBeginning(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    Node* insertEndRec(Node* temp, int val)
    {
        if (temp == NULL)
            return new Node(val);

        temp->next = insertEndRec(temp->next, val);

        return temp;
    }

    void insertEnd(int val)
    {
        head = insertEndRec(head, val);
    }

    Node* insertPosition(Node* temp, int val, int pos)
    {
        if (pos == 1)
        {
            Node* newNode = new Node(val);
            newNode->next = temp;
            return newNode;
        }

        temp->next = insertPosition(temp->next, val, pos - 1);

        return temp;
    }

    void insertAtPosition(int val, int pos)
    {
        head = insertPosition(head, val, pos);
    }

    Node* deleteValue(Node* temp, int val)
    {
        if (temp == NULL)
            return NULL;

        if (temp->data == val)
        {
            Node* del = temp->next;
            delete temp;
            return del;
        }

        temp->next = deleteValue(temp->next, val);

        return temp;
    }

    void deleteByValue(int val)
    {
        head = deleteValue(head, val);
    }

    Node* deletePosition(Node* temp, int pos)
    {
        if (temp == NULL)
            return NULL;

        if (pos == 1)
        {
            Node* del = temp->next;
            delete temp;
            return del;
        }

        temp->next = deletePosition(temp->next, pos - 1);

        return temp;
    }

    void deleteAtPosition(int pos)
    {
        head = deletePosition(head, pos);
    }

    int search(Node* temp, int val, int pos)
    {
        if (temp == NULL)
            return -1;

        if (temp->data == val)
            return pos;

        return search(temp->next, val, pos + 1);
    }

    int searchValue(int val)
    {
        return search(head, val, 1);
    }
};

int main()
{
    LinkedList list;

    list.insertBeginning(10);
    list.insertEnd(20);
    list.insertEnd(30);

    list.display();

    list.insertAtPosition(15, 2);

    list.display();

    list.deleteByValue(20);

    list.display();

    cout << "Position of 30: "
        << list.searchValue(30);

    return 0;
}