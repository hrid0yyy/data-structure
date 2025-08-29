#include <bits/stdc++.h>
using namespace std;

vector<int> merge(const vector<int>& a, const vector<int>& b) {
    vector<int> c;
    int i = 0, j = 0;
    int size_a = a.size(), size_b = b.size();
    while (i < size_a && j < size_b) {
        if (a[i] < b[j]) {
            c.push_back(a[i++]);
        } else {
            c.push_back(b[j++]);
        }
    }
    while (i < size_a) {
        c.push_back(a[i++]);
    }
    while (j < size_b) {
        c.push_back(b[j++]);
    }
    return c;
}

vector<int> mergesort(const vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return arr;
    }
    int mid = n / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    vector<int> sorted_left = mergesort(left);
    vector<int> sorted_right = mergesort(right);
    return merge(sorted_left, sorted_right);
}

