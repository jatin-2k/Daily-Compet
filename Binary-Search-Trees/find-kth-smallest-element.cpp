class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* temp = root;
        stack<TreeNode*> s;
        int it = 0; TreeNode* cur;
        while(it!=k){
            if(temp){
                s.push(temp);
                temp = temp->left;
            }
            else if(!s.empty()){
                it++;
                temp = s.top(); s.pop();
                cur = temp;
                temp = temp -> right;
            }
            else{
                cout<<"Fault";
            }
        }
        return cur->val;
    }
};
