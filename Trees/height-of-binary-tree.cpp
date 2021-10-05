class Solution{
    public:
    int height(struct Node* node){
        if(node){
            return max(height(node->left),height(node->right))+1;
        }
        return 0;
    }
};