#include<bits/stdc++.h>
using namespace std;

// maximum sub crossing array
int msca(int* arr, int start, int mid, int end){
    int leftSum = INT_MIN, rightSum = INT_MIN;
    int sum = 0;

    for(int i = mid; i >= start; i--){
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    for(int i = mid + 1; i <= end; i++){
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}


// maximum sub array
int msa(int* arr, int start, int end){
    if(start == end){
        return arr[start];
    }
    int mid = (start + end) / 2;
    int leftMax = msa(arr, start, mid);
    int rightMax = msa(arr, mid + 1, end);
    int crossMax = msca(arr, start, mid, end);
    return max({leftMax, rightMax, crossMax}); 
}


class Solution {
    public:
        int msca(vector<int>& arr, int start, int mid, int end){
            int leftSum = INT_MIN, rightSum = INT_MIN;
            int sum = 0;
        
            for(int i = mid; i >= start; i--){
                sum += arr[i];
                leftSum = max(leftSum, sum);
            }
        
            sum = 0;
            for(int i = mid + 1; i <= end; i++){
                sum += arr[i];
                rightSum = max(rightSum, sum);
            }
        
            return leftSum + rightSum;
        }
        
        
        // maximum sub array
        int msa(vector<int>& arr, int start, int end){
            if(start == end){
                return arr[start];
            }
            int mid = (start + end) / 2;
            int leftMax = msa(arr, start, mid);
            int rightMax = msa(arr, mid + 1, end);
            int crossMax = msca(arr, start, mid, end);
            return max({leftMax, rightMax, crossMax}); 
        }
        int maxSubArray(vector<int>& nums) {
            int end = nums.size() - 1;
            return msa(nums, 0, end);
        }
    };




int main(){

    vector<int> arr = {-1, 10, -1, 6, -2, -4, 2, 2, 8, -4};
    Solution sol;
    int maxSum = sol.maxSubArray(arr);
    cout << "Maximum Subarray Sum: " << maxSum << endl;

}