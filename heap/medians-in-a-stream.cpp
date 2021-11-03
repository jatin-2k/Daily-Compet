class Solution
{
    public:
    vector<int> harr;
    int size=0;
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(maxH.size() == 0 || maxH.top() > x){
            maxH.push(x);
        }
        else{
            minH.push(x);
        }
        balanceHeaps();
    }
    
    //7 1 6 8 10 9 1 3 0
    //max                 min
    //0 1 1 3 6           7 8 9 10
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxH.size() > minH.size()+1){
            minH.push(maxH.top());
            maxH.pop();
        }
        else if(minH.size()>maxH.size()){
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxH.size() == minH.size()){
            return (maxH.top()+minH.top())/2.0;
        }
        else{
            return maxH.top();
        }
    }
};