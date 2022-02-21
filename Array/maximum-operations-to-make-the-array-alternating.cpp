class Solution {
public:
    int n;
    int solveo(unordered_map<int,int> omp, unordered_map<int,int> emp, int mxo, int mxoc, int mxe, int mxec, int cur){
        omp.erase(mxo);
        mxo = 0; mxoc = 0;
        for(auto &p: omp){
            cur = p.second;
            if(cur > mxoc){
                mxoc = cur;
                mxo = p.first;
            }
        }
        return (n-1)/2 + 1 - mxec + n / 2 - mxoc;
    }
    int solvee(unordered_map<int,int> omp, unordered_map<int,int> emp, int mxo, int mxoc, int mxe, int mxec, int cur){
        emp.erase(mxe);
        mxe = 0; mxec = 0;
        for(auto &p: emp){
            cur = p.second;
            if(cur > mxec){
                mxec = cur;
                mxe = p.first;
            }
        }
        return (n-1)/2 + 1 - mxec + n / 2 - mxoc;
    }
    int minimumOperations(vector<int>& nums) {
        n = nums.size();
        int ans = INT_MAX;
        unordered_map<int,int> emp, omp;
        for(int i=0; i<n; i++){
            if(i%2==0){
                emp[nums[i]]++;
            }
            else{
                omp[nums[i]]++;
            }
        }
        int mxe = 0, mxec = 0, mxo = 0, mxoc = 0, cur = 0;
        for(auto &p: emp){
            cur = p.second;
            if(cur > mxec){
                mxec = cur;
                mxe = p.first;
            }
        }
        for(auto &p: omp){
            cur = p.second;
            if(cur > mxoc){
                mxoc = cur;
                mxo = p.first;
            }
        }
        ans = min(ans, solveo(omp, emp, mxo, mxoc, mxe, mxec, cur));
        ans = min(ans, solvee(omp, emp, mxo, mxoc, mxe, mxec, cur));
        if(mxe != mxo) ans = min(ans, (n-1)/2 + 1 - mxec + n / 2 - mxoc);
        return ans;
    }
};
