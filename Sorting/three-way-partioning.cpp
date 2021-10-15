class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        int n=array.size();
        int x=-1;
        for(int i=0; i<n; i++){
            if(array[i]<a){
                swap(array[++x], array[i]);
            }
        }
        x=n;
        for(int i=n-1; i>=0; i--){
            if(array[i]>b){
                swap(array[--x], array[i]);
            }
        }
    }
};