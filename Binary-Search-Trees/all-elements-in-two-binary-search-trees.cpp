class Solution {
public:
    void rec(TreeNode* root1, queue<int> &q){
        if(!root1) return;
        
        rec(root1->left,q);
        q.push(root1->val);
        rec(root1->right,q);
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        queue<int> q1,q2;
        rec(root1,q1);
        rec(root2,q2);
        vector<int> ans;
        while(!q1.empty() && !q2.empty()){
            if(q1.front() < q2.front()){
                ans.push_back(q1.front()); q1.pop();
            }
            else{
                ans.push_back(q2.front()); q2.pop();
            }
        }
        while(!q1.empty()){
            ans.push_back(q1.front()); q1.pop();
        }
        while(!q2.empty()){
            ans.push_back(q2.front()); q2.pop();
        }
        return ans;
    }
};