#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int partition(vector<int>& arr, int low, int high) {
            int pivot = arr[high];
            int i = low - 1;
            
            for (int j = low; j < high; j++) {
                if (arr[j] <= pivot) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);
            return i + 1;
        }
        
        int quickSelect(vector<int>& arr, int low, int high, int k) {
            if (low == high) {
                return arr[low];
            }
            
            int pivotIndex = partition(arr, low, high);
            
            if (pivotIndex == k) {
                return arr[pivotIndex];
            } else if (pivotIndex > k) {
                return quickSelect(arr, low, pivotIndex - 1, k);
            } else {
                return quickSelect(arr, pivotIndex + 1, high, k);
            }
        }
        
        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();
            // Convert kth largest to (n-k)th smallest (0-indexed)
            return quickSelect(nums, 0, n - 1, n - k);
        }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = sol.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;
    return 0;
}
