/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    
    TreeNode *root;
    int cnt = 0;
    int lv = 1;
    
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur = q.front(); q.pop();
            cnt++;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        TreeNode* cur = root;
        while(cur->left){
            cur = cur->left; lv++;
        }
    }
    
    int insert(int val) {
        TreeNode* cur = root;
        if(cnodes(lv) == cnt){
            while(cur->left){
                cur = cur->left;
            }
            cur->left = new TreeNode(val);
            cnt++; lv++;
            return cur->val;
        }
        int ans = root->val;
        insert(ans, lv-1, cnt, root, val);
        cnt++;
        return ans;
    }
    
    TreeNode* get_root() {
        return root;
    }
    
private:
    void insert(int &ans, int lv, int cnt, TreeNode *cur, int val){
        int mx = cnodes(lv);
        //cout<<"at: "<<cur->val<<"("<<lv<<","<<cnt<<")"<<" mx:"<<mx<<endl;
        if(!cur->left){
            cur -> left = new TreeNode(val);
            ans = cur->val;
            return;
        }
        if(!cur->right){
            cur -> right = new TreeNode(val);
            ans = cur->val;
            return;
        }
        if(mx > cnt-1-cnodes(lv-1)){
            insert(ans, lv-1, cnt-1-cnodes(lv-1), cur->left, val);
        }
        else{
            insert(ans, lv-1, cnt-1-mx, cur->right, val);
        }
    }
    
    int cnodes(int n){
        return pow(2,n)-1;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */