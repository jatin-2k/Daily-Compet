class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        queue<Node *> x;
        vector<int> ans;
        x.push(root);
        while(!x.empty()){
            Node *n = x.front();
            x.pop();
            if(n == NULL){
                ans.push_back(-1);
            }
            else{
                ans.push_back(n->data);
                x.push(n->left);
                x.push(n->right);
            }
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
        if(A.size() == 0 || A[0] == -1) return NULL;
        queue<Node*> q;
        Node *head = new Node(A[0]);
        q.push(head);
        int i=1;
        while(!q.empty() && i<A.size()){
            Node *n= q.front();
            if(A[i]==-1){ n->left = NULL; }
            else{
                n -> left = new Node(A[i]);
                q.push(n->left);
            }
            i++;
            if(A[i]==-1){ n->right = NULL; }
            else {
                n -> right = new Node(A[i]);
                q.push(n->right);
            }
            q.pop();
            i++;
        }
        return head;
    }
    

};