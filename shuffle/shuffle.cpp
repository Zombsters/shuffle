

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Node {
public:
    Node(int data);
    int data;
    Node* next;
    Node* prev;

};
Node::Node(int data) {
    this->data = data;
    next = NULL; prev = NULL;
}

void Shuffle(Node* head, int size);
Node* Split(Node* head,int median);
void Merge(Node*& head, Node* headTwo);

void AddAtHead(Node*& head,int data);
void Print(Node* head);
void PrintReverse(Node* head);

int main()
{
    Node* head = NULL;

    ifstream fin("Text.txt");
    int seed; fin >> seed; int size; fin >> size;
    srand(seed);
    for (int i = 0; i < size; i++) {
        AddAtHead(head, rand());
    }
    Print(head);

    Shuffle(head, size);
    cout << endl << endl;
    Print(head);
    cout << endl << endl;
    PrintReverse(head);
}

void Print(Node* head) {
    Node* traverse = head;
    while (traverse != NULL) {
        cout << traverse->data << " ";
        traverse = traverse->next;
    }
}

void PrintReverse(Node* head) {
    Node* traverse = head;
    while (traverse->next != NULL) {
        traverse = traverse->next;
    }

    while (traverse != NULL) {
        cout << traverse->data << " ";
        traverse = traverse->prev;
    }
}

void AddAtHead(Node*& head,int data) {
    Node* newNode = new Node(data);
    
    if (head == NULL) { //if list empty...
        head = newNode;
    }
    else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void Shuffle(Node* head, int size) {
    int median;
    if (size % 2 == 0) {
        median = (size / 2);
    }
    else {
        median = (size / 2);
    }

    Node* headTwo = Split(head,median);

    Merge(head, headTwo);

}

Node* Split(Node* head, int median) {

    Node* curr = head;
    Node* prev = NULL;

    int count = 0;
    while (count < median) {
        prev = curr;
        curr = curr->next;
        count++;
    }   

    //disconect Nodes
    prev->next = NULL;
    curr->prev = NULL;

    return curr;
}

void Merge(Node*& head, Node* headTwo) {
    Node* headThree = NULL;

    Node* curr = head; Node* currTwo = headTwo; Node* currThree = NULL;

    int count = 0;
    while (curr != NULL && currTwo != NULL) {
        if (count % 2 == 0) {
            if (headThree == NULL) {
                headThree = curr;
                currThree = headThree;
                curr = curr->next;
            }
            else {
                currThree->next = curr;
                curr->prev = currThree;

                currThree = currThree->next;
                curr = curr->next;
            }
        }
        else {
            currThree->next = currTwo;
            currTwo->prev = currThree;

            currThree = currThree->next;
            currTwo = currTwo->next;
        }
        count++;
    }

    while (curr != NULL) {
        currThree->next = curr;
        curr->prev = currThree;

        currThree = currThree->next;
        curr = curr->next;
    }

    while (currTwo != NULL) {
        currThree->next = currTwo;
        currTwo->prev = currThree;

        currThree = currThree->next;
        currTwo = currTwo->next;
    }

    head = headThree;
}











// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
