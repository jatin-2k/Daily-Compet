class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int a[], int N)
    {
        // Your code here
        Node* head = new Node(0);
        unordered_map<int,vector<int>> map;
        for(int i=0; i<N; i++){
            if(a[i]==-1){
                head->data = i;
            }
            else{
                map[a[i]].push_back(i);
            }
        }
        queue<Node*>q;
        q.push(head);
        while(!q.empty()){
            for(auto i: map[q.front()->data]){
                Node *n = new Node(i);
                if(!q.front()->left)q.front()->left = n;
                else q.front()->right = n;
                
                q.push(n);
            }
            q.pop();
        }
        return head;
    }
};