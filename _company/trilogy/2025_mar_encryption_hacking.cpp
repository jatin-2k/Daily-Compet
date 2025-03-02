#include <bits/stdc++.h>
using namespace std;

/*
* given a list of arrays, instruction count sec, validity period in sec find the strength of encryption & see if it can be hacked in given timeframe. 
*/


int countDivisors(vector<int> &arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> freq(maxVal + 1, 0);
    vector<int> divisors(maxVal + 1, 0);

    // Count occurrences of each number in arr
    for (int num : arr) freq[num]++;

    // Compute number of divisors for each number in arr
    for (int i = 1; i <= maxVal; ++i)
        for (int j = i; j <= maxVal; j += i)
            divisors[j] += freq[i];

    // Find the maximum divisor count among elements in arr
    int maxDivisors = 0;
    for (int num : arr)
        maxDivisors = max(maxDivisors, divisors[num]);

    return maxDivisors;
}

vector<int> encryptionValidity(int ic, int vp, vector<int> keys) {
	int divisors = countDivisors(keys);
	unsigned long long int t = ic*vp;
	t = t/100000;
	// cout<<t<<" :testing"<<endl;
	return {(t >= divisors), divisors*(100000)};
}

int main() {
	vector<int> arr = {83315, 22089, 19068, 64911, 67636, 4640, 80192, 98971}; // Example input
    auto res = encryptionValidity(9677958, 50058356, arr);
	// vector<int> arr = {2,2,4,8}; // Example input
 //   auto res = encryptionValidity(1000, 10000, arr);
    // vector<int> arr = {2,4}; // Example input
    // auto res = encryptionValidity(100, 1000, arr);
    // cout<<res;
    for (int x : res) cout << x << " ";
    return 0;
}
