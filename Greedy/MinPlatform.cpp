#include<bits/stdc++.h>
using namespace std;


int minPlatform(vector<int> arr, vector<int> dep){
	vector<pair<int, int>> events;
	for(int i = 0; i < arr.size(); i++){
		events.push_back({arr[i], 1});
	}
	for(int i = 0; i < dep.size(); i++){
		events.push_back({dep[i], -1});
	}
	sort(events.begin(),events.end());
	int platform = INT_MIN, curr = 0;
	for(int i = 0; i < events.size(); i++){
		curr += events[i].second;
		platform = max(platform, curr);
	}
	return platform;
}



int main() {

    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minPlatform(arr, dep);
    return 0;
}