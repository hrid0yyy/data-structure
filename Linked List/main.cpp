#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next; 

        Node(int value) {
            data = value;
            next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;

    public:
        LinkedList(){
            head = nullptr;
        }
        
        void insertAtEnd(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = newNode;
            }
        }

        int size(){
            Node* temp = head;
            int len = 0;
            if(head != nullptr){
                len++;
                while(temp->next != nullptr){
                    temp = temp->next;
                    len++;
                }
            }
            return len;
        }

        void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        }

        void reverse(){
        Node* temp = head;
        int len = size();
        if(len == 0){
            cout << "The list is empty";
            return;
        }
        else{
            Node *prev = nullptr;
            Node *current = head;
            Node *next = nullptr;
            
            while (current != nullptr) {
                // Store next node
                next = current->next;
                // Reverse the link
                current->next = prev;
                // Move prev and current one step forward
                prev = current;
                current = next;
            }
            
            // Update head to point to the last node (now first)
            head = prev;
        }
        }
    
};


int main(){
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display(); 
    list.reverse();
    list.display();
}