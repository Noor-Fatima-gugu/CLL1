#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int value) 
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList 
{
private:
    Node* head;
    Node* tail;

    
public:
    LinkedList()  
    {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList()
    {
        while (head) 
        {
            Node* temp = head;
            cout << head->data << " deleted" << endl;
            head = head->next;
            delete temp;
        }
    }

    void addAtHead(int value) 
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void addAtTail(int value) 
    {
        Node* newNode = new Node(value);
        if (!tail) 
        {
            head = tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addBefore(int targetValue, int newValue) 
    {
        if (!head) return;

        if (head->data == targetValue) 
        {
            addAtHead(newValue);
            return;
        }
        Node* prev = head;
        while (prev->next && prev->next->data != targetValue) 
        {
            prev = prev->next;
        }
        if (!prev->next) 
        {
            return;
        }
        Node* newNode = new Node(newValue);
        newNode->next = prev->next;
        prev->next = newNode;
        if (prev == tail) 
        {
            Node* curr = newNode;
            tail = newNode;
        }
    }
    void addAfter(int targetValue, int newValue) 
    {
        if (!head) return;
        Node* temp = head;
        while (temp && temp->data != targetValue) 
        {
            temp = temp->next;
        }
        if (!temp) 
        {
            return;
        }
        Node* newNode = new Node(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) 
        {
            tail = newNode;
        }
    }
    void deleteAtHead()
    {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) 
        {
            tail = nullptr;
        }
    }
    void deleteAtTail()
    {
        if (!tail) return;

        if (!head->next)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node* prev = head;
            while (prev->next != tail)
            {
                prev = prev->next;
            }
            delete tail;
            tail = prev;
            tail->next = nullptr;
        }
    }
    void deleteBefore(int targetValue)
    {
        if (!head || !head->next) return;

        if (head->data == targetValue)
        {
            deleteAtHead();
            return;
        }
        Node* prev = head;
        while (prev->next && prev->next->data != targetValue)
        {
            prev = prev->next;
        }
        if (!prev->next) return;
        Node* temp = prev->next;
        prev->next = temp->next;
        if (temp == tail)
        {
            tail = prev;
        }
        delete temp;
    }
    void deleteAfter(int targetValue)
    {
        if (!head) return;
        Node* current = head;
        while (current && current->data != targetValue)
        {
            current = current->next;
        }
        if (!current || !current->next) return;
        Node* temp = current->next;
        current->next = temp->next;
        if (temp == tail)
        {
            tail = current;
        }
        delete temp;
    }
    int getSize()
    {
        int size = 0;
        Node* temp = head;
        while (temp) 
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
    void reverse()
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        Node* temp = head;
        head = tail;
        tail = temp;
    }
    void display() 
    {
        Node* temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    list.addAtHead(20);
    list.addAfter(20, 5);
    list.addAtTail(30);
    //list.deleteBefore(30);
    list.display();
    list.reverse();
    list.display();



    return 0;
}