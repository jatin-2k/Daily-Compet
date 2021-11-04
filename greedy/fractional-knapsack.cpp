class Solution
{
    
    public:
    static bool compare(Item a, Item b){
        
        return (double)a.value/(double)a.weight > (double)b.value/(double)b.weight;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n, compare);
        int size=0;
        double profit=0;
        int i=0;
        while(size != W and i<n){
            if(arr[i].weight <= W-size){
                size+=arr[i].weight;
                profit+=arr[i].value;
            }
            else{
                profit+= (double)arr[i].value/(double)arr[i].weight*(W-size);
                size = W;
            }
            i++;
        }
        return profit;
    }
        
};