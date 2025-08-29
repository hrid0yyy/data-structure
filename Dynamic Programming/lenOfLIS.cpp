#include<bits/stdc++.h>
using namespace std;

int dfs(int index, long long prev_val, const vector<int>& nums) {
    // Base case: if index reaches the end of array
    if (index >= nums.size()) {
        return 0;
    }
    
    // Option 1: Skip the current element
    int skip = dfs(index + 1, prev_val, nums);
    
    // Option 2: Include the current element if it's valid
    int include = 0;
    if (nums[index] > prev_val) {
        include = 1 + dfs(index + 1, nums[index], nums);
    }
    
    // Return the maximum length
    return max(skip, include);
}


int dynamic(const vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int maxLength = 1;
    for(int i = nums.size()-1 ; i >= 0; --i){
        for(int j = i; j < nums.size(); ++j){
           if(nums[j] > nums[i]){
                dp[i] = max(dp[i], 1 + dp[j]);
                maxLength = max(maxLength, dp[i]);
            }
        }
    }
    return maxLength;
}

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            return dynamic(nums);
        }
    };

int main(){
    vector<int> nums = {10, 9, 2, 5};
    Solution sol;
    cout << sol.lengthOfLIS(nums) << endl; 
    return 0;
}