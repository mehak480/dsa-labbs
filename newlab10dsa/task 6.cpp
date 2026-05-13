#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int d)
    {
        data = d;
        next = prev = NULL;
    }
};

class DoublyList
{
private:
    Node* head;

public:
    DoublyList()
    {
        head = NULL;
    }

    void insertEnd(Node*& temp, int val)
    {
        if (temp == NULL)
        {
            temp = new Node(val);
            return;
        }

        if (temp->next == NULL)
        {
            Node* newNode = new Node(val);
            temp->next = newNode;
            newNode->prev = temp;
            return;
        }

        insertEnd(temp->next, val);
    }

    void insert(int val)
    {
        insertEnd(head, val);
    }

    void printForward(Node* temp)
    {
        if (temp == NULL)
        {
            cout << endl;
            return;
        }

        cout << temp->data << " ";

        printForward(temp->next);
    }

    void display()
    {
        printForward(head);
    }

    Node* getLast(Node* temp)
    {
        if (temp->next == NULL)
            return temp;

        return getLast(temp->next);
    }

    bool palindrome(Node* left, Node* right)
    {
        if (left == right || right->next == left)
            return true;

        if (left->data != right->data)
            return false;

        return palindrome(left->next, right->prev);
    }

    bool isPalindrome()
    {
        if (head == NULL)
            return true;

        Node* last = getLast(head);

        return palindrome(head, last);
    }
};

int main()
{
    DoublyList list;

    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(1);

    list.display();

    if (list.isPalindrome())
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}