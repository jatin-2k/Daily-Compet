class Solution{
public:
    void rotateArr(int arr[], int d, int n){
        // code here
        reverse(arr,arr+n-d);
        reverse(arr+n-d,arr+n);
        reverse(arr,arr+n);
    }
};