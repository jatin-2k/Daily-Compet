class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        
        //similar to level order
        deque<TreeNode *> q;
        int count = 0, maxwidth =0;
        q.push_front(root);
        
        while(!q.empty()){
            
            while(!q.empty() && q.back()==NULL){
                q.pop_back(); //removing NULL nodes at the end
            }
            
            while(!q.empty() && q.front()==NULL){
                q.pop_front(); //removing NULL nodes in the front
            }
            
            int sz = q.size();
            maxwidth = max(maxwidth, sz);
            
            for(int i=0; i<sz; i++){
                TreeNode *tmp = q.front();
                q.pop_front();
                if(tmp){
                    q.push_back(tmp->left);
                    q.push_back(tmp->right);
                }
                
                else{
                    q.push_back(NULL);
                    q.push_back(NULL);
                }
            }
        }
        
        return maxwidth;
        
    }
};