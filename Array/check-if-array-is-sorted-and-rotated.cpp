class Solution{
    public:
    // arr: input array
    // num: length of array
    // This function returns true or false
    //Function to check if array is sorted and rotated.
    bool AS(int arr[], int n){
        // Your code here
        int i=0;
        while(i<n-1 and arr[i]<arr[i+1]) i++;
        if(i>=n-1) return false;
        
        i++;
        for(int j=0; j<n-1; j++, i++){
            i=i%n;
            if(arr[i]>arr[(i+1)%n]) return 0;
        }
        return 1;
    }
    
    bool DS(int arr[], int n){
        // Your code here
        int i=0;
        while(i<n-1 and arr[i]>arr[i+1]) i++;
        if(i>=n-1) return false;
        
        i++;
        for(int j=0; j<n-1; j++, i++){
            i=i%n;
            if(arr[i]<arr[(i+1)%n]) return 0;
        }
        return 1;
    }
    
    bool checkRotatedAndSorted(int arr[], int n){
        return AS(arr,n) || DS(arr,n);
        
    }
};