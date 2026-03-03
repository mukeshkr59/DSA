#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head; // Creating a cycle

    // Detecting cycle using Floyd's Tortoise and Hare algorithm
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next; // Move slow by 1
        fast = fast->next->next; // Move fast by 2

        if (slow == fast) { // Cycle detected
            cout << "Cycle detected in the linked list." << endl;
            return 0;
        }
    }

    cout << "No cycle detected in the linked list." << endl;
    return 0;
}