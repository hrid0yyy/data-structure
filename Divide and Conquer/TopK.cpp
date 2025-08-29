#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        void count(map<int, int>& frequencyMap, vector<int>& nums, int k, int start, int end) {
            if(start == end){
                frequencyMap[nums[start]]++;
                return;
            }
            int mid = (start + end) / 2;
            count(frequencyMap, nums,  k, start, mid);
            count(frequencyMap, nums,  k, mid + 1, end);
        }
        vector<int> topKFrequent(vector<int>& nums, int k) {
            map<int, int> frequencyMap;
            int n = nums.size();
            count(frequencyMap, nums, k, 0, n - 1);
            vector<pair<int, int>> frequencyVector(frequencyMap.begin(), frequencyMap.end());
            sort(frequencyVector.begin(), frequencyVector.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;
            });
            vector<int> results;
            for (int i = 0; i < k && i < frequencyVector.size(); i++) {
                results.push_back(frequencyVector[i].first);
            }
           
            return results;
            
        }
    };

int main(){
    Solution sol;
    vector<int> nums = {4,1,-1,2,-1,2,3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    
    cout << "The top " << k << " frequent elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}