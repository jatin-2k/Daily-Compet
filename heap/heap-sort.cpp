class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        // Your Code Here
        int l = 2*i+1;
        int r = 2*i+2;
        int maxx = i;
        if(l<n and arr[l] > arr[i]){
          maxx = l;
        }
        if(r<n and arr[r] > arr[maxx]){
          maxx = r;
        }
        if( i<n and maxx != i){
          swap(arr[i], arr[maxx]);
          heapify(arr,n,maxx);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for(int i=(n-2)/2; i>=0; i--){
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        for(int i=0; i<n; i++){
            swap(arr[0],arr[n-1-i]);
            heapify(arr,n-1-i,0);
        }
    }
};
