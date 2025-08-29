#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<vector<int>>& matrix, int first, int last, int target){
        if(first == last){
            for(int i = 0; i < matrix[first].size(); i++){
                if(matrix[first][i] == target){
                    return 1;
                }
            }
            return 0;
        }
        int mid = (first+last)/2;
        int left = search(matrix, first, mid, target);
        int right = search(matrix, mid+1, last, target);
        return max(left,right);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix, 0, matrix.size()-1, target);
    }
};


int main()
{
    vector<vector<int>> matrix = {{1,4,3},{2,3,4}};
      for(int i = 0; i < matrix[0].size(); i++){
                if(matrix[0][i] == 2){
                    cout << "paisi";
                }
            }
    Solution sol;
    cout << sol.searchMatrix(matrix, 4);

}