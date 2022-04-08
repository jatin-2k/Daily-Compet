class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minH;
    int k;
    KthLargest(int k, vector<int>& nums) {
        for(auto i: nums){
            minH.push(i);
            while(minH.size() > k) minH.pop();
        }
        this->k = k;
    }
    
    int add(int val) {
        minH.push(val);
        while(minH.size() > k) minH.pop();
        return minH.top();
    }
};