class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        queue<Node*> q;
        vector<int> ans;
        q.push(node);
        while(!q.empty()){
            Node* n = q.front();
            q.pop();
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
            ans.push_back(n->data);
        }
        return ans;
    }
};