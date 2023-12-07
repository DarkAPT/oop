#include <iostream>
#include <stdexcept>

using namespace std;

class Node{
public: 
    Node *next;
    int data;
    Node *previous;
};


class SingleLinkedList{
private:
    Node *head;
    int size;
public:
    SingleLinkedList(){
        head = NULL;
        size = 0;
    }

    ~SingleLinkedList(){
        Node *current = head;
        while(current != NULL){
            delete current;
            current = current -> next;
        }
    }

    void insert(int n){
        size++;
        Node *newnode = new Node;
        newnode -> data = n;
        newnode -> next = NULL;

        if (head == NULL){
            head = newnode;
        }
        else{
            Node *current = head;

            while (current -> next != NULL){
                current = current -> next;
            }
            current -> next = newnode;
        }
    }

    void insertBegin(int n){
        size++;
        Node *node = new Node;
        node ->data = n;
        node -> next = NULL;
        if (head == NULL){
            head = node;
        }
        else{
            Node *current = head;
            head = node;
            head ->next = current;
        }
    }

    void insertInto(int n, int i){
        size++;
        Node *node = new Node;
        node -> data = n;
        int count = 1;
        if (size < i or i<0){
            throw out_of_range("Index out of range");
        }
        else{
            Node *current = head;  
            while(count != i){
                count++;
                current = current -> next;
            }
            node -> next = current -> next;
            current -> next = node;
        }
    }

    int len(){
        return size;
    }

    void printList(){
        Node *current = head;
        while(current != NULL){
            cout << current -> data << " ";
            current = current -> next;
        }
        cout<<endl;
    }

};


class CircularLinkedList{
private:
    Node *head;
    Node *tail;
    int size;
public:
    CircularLinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~CircularLinkedList(){
        if (head){
            Node* node = tail;
            while (node != head){
                node -> next = head -> next;
                delete head;
                head = node -> next;
            }
            if (node == head){
                delete head;
                head = NULL;
            }
        }
    }

    void insert(int n){
        size++;
        Node *newnode = new Node;
        newnode -> data = n;
        newnode -> next = head;
        if (head != NULL){
            tail -> next = newnode;
            tail = newnode;
        }
        else
        head = tail = newnode;
    }

    void insertBegin(int n){
        size++;
        Node *node = new Node;
        node ->data = n;
        node ->next = head;
        if (head != NULL){
            tail -> next = node;
            head = node;
        }
        else
        head = tail = node;
    }

    void insertInto(int n, int i){
        size++;
        Node *node = new Node;
        node -> data = n;
        int count = 1;
        if (size < i){
            throw out_of_range("Index out of range");
        }
        else{
            Node *current = head;  
            while(count != i){
                count++;
                current = current -> next;
            }
            node -> next = current -> next;
            current -> next = node;
        }
    }

    int len(){
        return size;
    }

    void printList(){
        Node *newnodeHead = new Node;
        newnodeHead = head;
        int temp = size;
        while( temp + 1!= 0){
            cout<< newnodeHead -> data << " ";
            newnodeHead = newnodeHead -> next;
            temp --;
        }
        cout<<endl;
    }
};


class DoubleLinkedList{
private:
    Node *head;
    Node *tail;
    int size;
public:
    DoubleLinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~DoubleLinkedList(){
        while(head){
            tail = head -> next;
            delete head;
            head = tail;
        }
    }

    void insert(int n){
        size++;
        Node *node = new Node;
        node -> next = NULL;
        node -> data = n;

        if(head != NULL){
            node ->previous = tail;
            tail ->next = node;
            tail = node;
        }
        else{
            node -> previous = NULL;
            head = tail = node;
        }
    }

    void insertBegin(int n){
        size++;
        Node *node = new Node;
        node -> data = n;
        node -> next = head;
        if (head != NULL){
            node -> previous = NULL;
            head -> previous = node;
            head = node;
        }
        else{
            node -> previous = NULL;
            head = tail = node;
        }
    }

    void insertInto(int n, int i){
        size++;
        Node *node = new Node;
        node -> data = n;
        int count = 1;
        if (size < i){
            throw out_of_range("Index out of range");
        }
        else{
            Node *current = head;  
            while(count != i){
                count++;
                current = current -> next;
            }
            node -> next = current -> next;
            current ->next -> previous = node;
            node -> previous = current;
            current -> next = node;
        }
    }

    int len(){
        return size;
    }

    void printList(){
        Node *node = tail;
        while (node != NULL){
            cout << node -> data << " ";
            node = node -> previous;
        }
        cout << "\n";
        node = head;
        while(node != NULL){
            cout << node -> data << " ";
            node = node -> next;
        }
        cout<<endl;
    }
};


int main(){
    cout << "Пример односвязного списка:\n";
    SingleLinkedList testList;
    testList.insert(1);
    testList.insert(8);
    testList.insert(22);
    testList.printList();

    cout << endl << "Пример добавления числа в начало списка:\n";
    cout << "Список до добавления элемента:"<< endl;
    testList.printList();
    cout << "\n" <<"Список после добавления элемента:\n";
    testList.insertBegin(100);
    testList.printList();

    cout << "\n" <<"Пример добавления числа в список по 'индексу':\n";
    cout << "Список до добавления элемента:"<< endl;
    testList.printList();
    cout <<"\n"<< "Список после добавления элемента:"<< endl;
    testList.insertInto(80,2);
    testList.printList();

    cout << endl<<"_____________________________________________________";

    cout <<"\n" <<"Пример циклического списка:" << endl;
    CircularLinkedList test;
    test.insert(1);
    test.insert(3);
    test.insert(4);
    test.printList();

    cout << endl << "Пример добавления числа в начало списка:\n";
    cout << "Список до добавления элемента:"<< endl;
    test.printList();
    test.insertBegin(100);
    cout << "\n" <<"Список после добавления элемента:\n";
    test.printList();

    cout << "\n" <<"Пример добавления числа в список по 'индексу':\n";
    cout << "Список до добавления элемента:"<< endl;
    test.printList();
    test.insertInto(50,3);
    cout <<"\n"<< "Список после добавления элемента:"<< endl;
    test.printList();

    cout << endl<<"_____________________________________________________";

    cout << "\n"<<"Пример двусвязного списка:" << endl;
    DoubleLinkedList test2;
    test2.insert(4);
    test2.insert(2);
    test2.insert(1);
    test2.printList();

    cout << endl << "Пример добавления числа в начало списка:\n";
    cout << "Список до добавления элемента:"<< endl;
    test2.printList();
    cout <<"\n"<< "Список после добавления элемента:"<< endl;
    test2.insertBegin(100);
    test2.printList();

    cout << "\n" <<"Пример добавления числа в список по 'индексу':\n";
    cout << "Список до добавления элемента:"<< endl;
    test2.printList();
    cout <<"\n"<< "Список после добавления элемента:"<< endl;
    test2.insertInto(99,2);
    test2.printList();

    cout <<"_____________________________________________________";
}