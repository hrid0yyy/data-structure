#include<bits/stdc++.h>
using namespace std;

// Structure to hold two things together:
// 1. The inversion count
// 2. The sorted array after merge
struct Output {
    int count;
    vector<int> arr;
};


// Merge step: merges two sorted subarrays and counts inversions across them
Output merge(Output left, Output right) {
    vector<int> leftarr = left.arr;     // sorted left half
    vector<int> rightarr = right.arr;   // sorted right half
    vector<int> merge;                  // merged sorted array
    int count = 0, i = 0, j = 0;        // inversion count, and two pointers

    int leftarrsize = leftarr.size();
    int rightarrsize = rightarr.size();

    // Merge like in merge sort, but also count inversions
    while(i < leftarrsize && j < rightarrsize) {
        if(leftarr[i] < rightarr[j]) {
            // If left element is smaller, no inversion
            merge.push_back(leftarr[i]);
            i++;
        }
        else if(leftarr[i] > rightarr[j]) {
            // If right element is smaller, inversion occurs
            merge.push_back(rightarr[j]);
            j++;
            // All remaining elements in leftarr[i...end] will form inversions with rightarr[j]
            count = count + (leftarrsize - i);
        }
    }

    // Copy remaining elements of left half (if any)
    while(i < leftarrsize) {
        merge.push_back(leftarr[i]);
        i++;
    }

    // Copy remaining elements of right half (if any)
    while(j < rightarrsize) {
        merge.push_back(rightarr[j]);
        j++;
    }

    // Total inversions = cross inversions + inversions inside left + inversions inside right
    count = count + left.count + right.count;

    // Return both inversion count and merged sorted array
    return {count, merge};
}


// Recursive function to count inversions using Merge Sort approach
Output count_inversion_using_mergesort(vector<int>& arr, int start, int end) {
    // Base case: single element, no inversions
    if(start == end) {
        return {0, {arr[start]}};
    }

    int mid = (start + end) / 2;

    // Count inversions in left half
    Output left = count_inversion_using_mergesort(arr, start, mid);

    // Count inversions in right half
    Output right = count_inversion_using_mergesort(arr, mid + 1, end);

    // Count cross inversions while merging left and right halves
    return merge(left, right);
}


int main() {
    vector<int> arr = {4, 3, 2, 1};

    // Call inversion counter and print result
    cout << count_inversion_using_mergesort(arr, 0, arr.size() - 1).count;
}
