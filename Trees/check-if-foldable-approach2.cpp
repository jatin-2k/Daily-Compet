class Solution{
    public:
    void inl(Node *root, vector<Node*> &ans){
        if(root){
            ans.push_back(root);
            inl(root->left,ans);
            inl(root->right,ans);
        }
        else{
            ans.push_back(root);
        }
    }
    void inr(Node *root, vector<Node*> &ans){
        if(root){
            inr(root->left,ans);
            inr(root->right,ans);
            ans.push_back(root);
        }
        else{
            ans.push_back(root);
        }
    }
    
    bool IsFoldable(Node* root)
    {
        if(!root) return true;
        vector<Node *> l,r;
        inl(root->left, l);
        inr(root->right,r);
        if(l.size()!= r.size()) return false;
        for(int i=0; i<l.size(); i++){
            if( (l[i] && r[l.size()-i-1]) || (!l[i] && !r[l.size()-i-1]) ){
                
                continue;
            }
            else{
                
                return false;
            }
        }
        return true;
    }
};