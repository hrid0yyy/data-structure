#include <iostream>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        if (list1) {
            current->next = list1;
        } else if (list2) {
            current->next = list2;
        }
        
        return dummy.next;
    }
};

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    std::cout << "[";
    while (current) {
        std::cout << current->val;
        if (current->next) std::cout << ",";
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

// Helper function to delete a linked list (to avoid memory leaks)
void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    // Test case: list1 = [1,2,4], list2 = [1,3,4]
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    // Create linked lists
    ListNode* list1 = createList(arr1, size1);
    ListNode* list2 = createList(arr2, size2);
    
    // Print input lists
    std::cout << "List1: ";
    printList(list1);
    std::cout << "List2: ";
    printList(list2);
    
    // Merge lists
    Solution solution;
    ListNode* merged = solution.mergeTwoLists(list1, list2);
    
    // Print merged list
    std::cout << "Merged List: ";
    printList(merged);
    
    // Clean up memory
    deleteList(merged);
    
    return 0;
}