// Function to return the level order traversal of a BST.
vector<int> levelOrder(struct Node* node) {
    // code here
    queue<Node*> q;
    vector<int> ans;
    q.push(node);
    
    while(!q.empty()){
        vector<Node*> temp;
        while(!q.empty()){
            temp.push_back(q.front());
            q.pop();
        }
        for(auto &i: temp){
            ans.push_back(i->data);
            if(i->left)q.push(i->left);
            if(i->right)q.push(i->right);
        }
    }
    return ans;
}