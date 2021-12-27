#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> nums, int n){
	sort(nums.begin(), nums.end());
	for(int i=0; i<n; i++) if(nums[i] > i+1) return false;
	return true;
}

int moveZeroDown(int x, vector<int>& nums, int n){
	int ans = 0;
	if(nums[x+1]==0) ans += moveZeroDown(x+1, nums, n);
	ans++; nums[x]++; nums[x+1]--;
	swap(nums[x],nums[x+1]);
	return ans;
}

int solve(vector<vector<bool>> &arr,vector<int> nums, int n){
	for(int i=0; i<n; i++){
		nums[i] = (!nums[i])? i: i-nums[i]+1;
	}
	int ans = 0;
	for(int i=n-1; ~i; i--){
		if(nums[i]<0){
			if(nums[i+1]==0){
				ans += moveZeroDown(i+1, nums, n);
			}
			ans++; nums[i]++; nums[i+1]--;
			swap(nums[i],nums[i+1]);
			i = n-1;
		}
	}
	return ans;
}

int RedGreenBalls(vector<vector<char>> &balls, int n){
    vector<vector<bool>> arr;
	vector<int> nums;
	for(int i=0; i<n; i++){
		vector<bool> temp(n); int m=0;
		for(int j=0; j<n; j++){
			temp[j]=(balls[i][j]=='R')?1:0;
			if(temp[j]) m = j+1;
		}
		nums.push_back(m);
		arr.push_back(temp);
	}
	if(isPossible(nums,n)){
		return solve(arr,nums,n);
	}
	else{
		return -1;
	}
}

int main() {
	vector<vector<char>> arr;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		vector<char> temp(n);
		for(int j=0; j<n; j++){
            cin>>temp[j];
		}
		arr.push_back(temp);
	}
    cout<<RedGreenBalls(arr,n);
	return 0;
}
