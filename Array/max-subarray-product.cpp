int maxSubarrayProduct(vector<int> arr, int n)
{
    int res = arr[0];
    int curMax = arr[0];
    int curMin = arr[0];
    for(int i=1; i<arr.size(); i++){
        int temp = max({
                    arr[i],
                    arr[i]*curMax,
                    arr[i]*curMin
                    });
        curMin = min({
                    arr[i],
                    arr[i]*curMax,
                    arr[i]*curMin
                    });
        curMax = temp;
        res = max(res,curMax);
    }
    return res;
}
//{-3,-1,5,-15,4} -> 300