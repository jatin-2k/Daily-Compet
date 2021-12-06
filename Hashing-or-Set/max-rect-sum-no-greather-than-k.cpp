class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        int ans =INT_MIN;
        //s = start; 
        for(int s=0; s<row; s++){
            vector<int> colSum(col,0);
            for(int cr=s; cr<row; cr++){
                for(int cc=0; cc<col; cc++){
                    colSum[cc]+=mat[cr][cc];
                }
                ans = max(ans, maxSubarraySum(colSum,k));
            }
        }
        return ans;
    }
    
    // Function to maximum required sum < K
    int maxSubarraySum(vector<int> &arr, int K)
    {
        int N = arr.size();
        // Hash to lookup for value (cum_sum - K)
        set<int> cum_set;
        cum_set.insert(0);

        int max_sum = INT_MIN, cSum = 0;

        for (int i = 0; i < N; i++) {

            // getting cummulative sum from [0 to i]
            cSum += arr[i];

            // lookup for upperbound
            // of (cSum-K) in hash
            set<int>::iterator sit
                = cum_set.lower_bound(cSum - K);

            // check if upper_bound
            // of (cSum-K) exists
            // then update max sum
            if (sit != cum_set.end())

                max_sum = max(max_sum, cSum - *sit);

            // insert cummulative value in hash
            cum_set.insert(cSum);
        }

        // return maximum sum
        // lesser than K
        return max_sum;
    }
};