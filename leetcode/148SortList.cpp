#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* shift(ListNode* l, int amount, ListNode** prev) {
        ListNode* temp = l;
        *prev = nullptr;
        while (amount > 0 && temp) {
            *prev = temp;
            temp = temp->next;
            amount--;
        }
        return temp;
    }

    ListNode* mergesort(ListNode* l, int len) {
        // Base case: empty list or single node
        if (!l || !l->next || len <= 1) {
            return l;
        }

        // Step 1: Split the list into two halves
        int leftLen = len / 2;
        int rightLen = len - leftLen;
        ListNode* prev = nullptr;
        ListNode* right = shift(l, leftLen, &prev);
        if (prev) {
            prev->next = nullptr; // Split the list
        }
        ListNode* left = l;

        // Step 2: Recursively sort both halves
        left = mergesort(left, leftLen);
        right = mergesort(right, rightLen);

        // Step 3: Merge the sorted halves
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while (left && right) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if (left) {
            temp->next = left;
        }
        if (right) {
            temp->next = right;
        }
        return dummy.next;
    }

    void printList(ListNode* head) {
        ListNode* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ListNode* sortList(ListNode* head) {
        int len = getLength(head);
        return mergesort(head, len);
    }
};

int main() {
    // Create the linked list using pointers
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution sol;
    cout << "Original list: ";
    sol.printList(head);

    head = sol.sortList(head);
    cout << "Sorted list: ";
    sol.printList(head);

    // Clean up memory
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}