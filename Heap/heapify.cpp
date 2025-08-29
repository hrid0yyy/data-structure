#include<bits/stdc++.h>
using namespace std;


void maxheapify(vector<int>& arr,int arrSize, int index){
	int leftChild = 2*index + 1;
	int rightChild = 2*index + 2;
	int largest = index;
	if(arr[leftChild] > arr[largest] && leftChild < arrSize){
			largest = leftChild;
	} 
	if(arr[rightChild] > arr[largest] && rightChild < arrSize){
			largest = rightChild;
	} 
	if(largest != index){
		swap(arr[index],arr[largest]);
		maxheapify(arr, arrSize, largest);
	}
}

void printheap(vector<int>& arr){
	for(int i = 0; i < arr.size() ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void build_max_heap(vector<int>& arr){
	int n = arr.size();
	if(n <= 1) return;
	int lastnode = n/2 + 1;
	for(int i = lastnode - 1; i >= 0; i--){
		maxheapify(arr, n, i);
	}
}

int deleteRoot(vector<int>& arr){
	int n = arr.size();
	int root = arr[0];
	arr[0] = arr[n-1];
	arr.pop_back();
	maxheapify(arr, n-1, 0);
	return root;
}

void insertHeap(vector<int>& arr, int val){
	arr.push_back(val);
	build_max_heap(arr);
}

void heapsort(vector<int> arr){
	int n = arr.size();
	for(int i = 0; i < n; i++){
		cout << deleteRoot(arr) << " ";
	}
	cout << endl;
}

int main(){
	vector<int> arr = {10, 2, 4, 5, 3};
	build_max_heap(arr);
	insertHeap(arr, 15);
	insertHeap(arr, 1);
	heapsort(arr);
	
}