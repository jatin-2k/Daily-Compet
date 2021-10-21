struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
//The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

void convert(Node *head, TreeNode *&root) {
    queue<TreeNode*> q;
    
    root=new TreeNode(head->data);
    
    q.push(root);
    head=head->next;
    
    while(!q.empty()){
    
        TreeNode* parent=q.front();
        q.pop();
        
        if(head!=nullptr){
            parent->left=new TreeNode(head->data);
            q.push(parent->left);
            head=head->next;
        }
        
        if(head!=nullptr){
            parent->right=new TreeNode(head->data);
            q.push(parent->right);
            head=head->next;
        }
    }
}