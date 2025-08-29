#include<bits/stdc++.h>
using namespace std;

struct output {
    int min, sec_min, sec_max, max;
};


output secondMaxmin(vector<int> arr, int start, int end){
    if(start == end){
        // Let second min be infinity and second max be negative infinity
        return {arr[start], INT_MAX , INT_MIN , arr[start]};
    }
    int mid = (start + end) / 2;
    output left = secondMaxmin(arr, start, mid); 
    output right = secondMaxmin(arr, mid + 1, end); 

    int left_max = left.max;
    int left_2nd_max = left.sec_max;
    int left_min = left.min;
    int left_2nd_min = left.sec_min;

    int right_max = right.max;
    int right_2nd_max = right.sec_max;
    int right_min = right.min;
    int right_2nd_min = right.sec_min;

    int combined_max, combined_2nd_max, combined_min, combined_2nd_min;
    if(left_max < right_max){
        combined_max = right_max;
        combined_2nd_max = max(left_max, right_2nd_max);
    } else {
        combined_max = left_max;
        combined_2nd_max = max(right_max, left_2nd_max);
    }
    if(left_min > right_min){
        combined_min = right_min;
        combined_2nd_min = min(left_min, right_2nd_min);
    } else {
        combined_min = left_min;
        combined_2nd_min = min(right_min, left_2nd_min);
    }

    return {combined_min, combined_2nd_min, combined_2nd_max, combined_max};
}


int main(){
    vector<int> arr = {-3, 1, 4, -1, 5, 9, -2, 6, 5};
    output result = secondMaxmin(arr, 0, arr.size() - 1);
    cout << "Second Maximum: " << result.sec_max << ", Second Minimum: " << result.sec_min << endl;
    // Output: Second Maximum: 6, Second Minimum: -2
}