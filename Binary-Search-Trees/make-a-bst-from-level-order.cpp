Node* constructBst(int arr[], int n)
{
    // Code here
    queue<pair<Node*,pair<int,int>>> q;
    Node *root = new Node(arr[0]);
    q.push({root,{INT_MIN, INT_MAX}});
    int i=1;
    while(!q.empty() and i<n){
        if(arr[i] > q.front().second.first && arr[i] < q.front().first -> data){
            Node *l = new Node(arr[i++]);
            q.front().first -> left = l;
            q.push({l,{q.front().second.first, q.front().first->data}});
        }
        if(i>=n) break;
        if(arr[i] > q.front().first->data && arr[i] < q.front().second.second){
            Node *r = new Node(arr[i++]);
            q.front().first -> right = r;
            q.push({r,{q.front().first -> data, q.front().second.second}});
        }
        q.pop();
    }
    return root;
}