class Node{
    public:
    int data;
    int i;
    int j;
    Node(int d, int row){
        data = d; i = row; j = 0;
    }
};

class Compare
{
public:
    bool operator() (Node a, Node b)
    {
        return a.data > b.data;
    }
};


class Solution
{
    public:
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node, vector<Node>, Compare> minH;
        vector<int> ans(K*K);
        for(int i=0; i<K; i++){
            Node n(arr[i][0], i);
            minH.push(n);
        }
        int x = 0;
        while(!minH.empty() and x<K*K){
            Node n = minH.top();
            minH.pop();
            ans[x++] = n.data;
            n.j++;
            if(n.j < K){
                n.data = arr[n.i][n.j];
                minH.push(n);
            }
        }
        return ans;
    }
};