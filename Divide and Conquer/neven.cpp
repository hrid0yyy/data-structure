#include<bits/stdc++.h>
using namespace std;

int numOfEven(int* arr, int start, int end){
    if(start == end){
       return arr[start] % 2 == 0 ? 1 : 0;
    }
    int mid = (start + end) / 2;
    int leftCount = numOfEven(arr, start, mid);
    int rightCount = numOfEven(arr, mid + 1, end);
    return leftCount + rightCount;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int evenCount = numOfEven(arr, 0, n - 1);
    cout << "Number of Even Elements: " << evenCount << endl;


}