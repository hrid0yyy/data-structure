
#include<bits/stdc++.h>
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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* merged = new ListNode(0);
        ListNode* temp = merged;
        while (left && right) {
            if (left->val <= right->val) {
                merged->next = left;
                left = left->next;
            } else {
                merged->next = right;
                right = right->next;
            }
            merged = merged->next;
        }
    
        if(left) merged->next = left;
        else merged->next = right;
     

        return temp->next;
    }
    ListNode* mergesort(vector<ListNode*>& arr, int start, int end){
        if(start == end){
            return arr[start];
        }
        int mid = (start+end) / 2;
        ListNode* left = mergesort(arr, start, mid);
        ListNode* right = mergesort(arr, mid+1, end);
        return merge(left, right);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergesort(lists, 0, lists.size()-1);
    }
};

int main(){

    // Create test case: three sorted linked lists
    // List 1: 1->4->5
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    
    // List 2: 1->3->4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    
    // List 3: 2->6
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);
    
    // Put lists into a vector
    std::vector<ListNode*> lists = {l1, l2, l3};
    
    Solution solution;
    // Merge lists
    ListNode* result = solution.mergeKLists(lists);
    
    // Print merged list
    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;


    
}