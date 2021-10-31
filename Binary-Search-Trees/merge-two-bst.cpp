class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        stack<Node*> s1,s2;
        vector<int> ans;
       //Your code here
       int i = 10;
       while(1){
           if(root1){
               s1.push(root1);
               root1 = root1->left;
           }
           else if(root2){
               s2.push(root2);
               root2 = root2->left;
           }
           else if(!s1.empty() && !s2.empty()){
               root1 = s1.top();
               root2 = s2.top();
               if(root1->data < root2->data) {
                   ans.push_back(root1->data);
                   root1 = root1->right;
                   root2 = NULL;
                   s1.pop();
               }
               else {
                   ans.push_back(root2->data);
                   root2 = root2->right;
                   root1 = NULL;
                   s2.pop();
               }
           }
           else if(!s1.empty()){
               root1 = s1.top();
               ans.push_back(root1->data);
               root1 = root1->right;
               s1.pop();
           }
           else if(!s2.empty()){
               root2 = s2.top();
               ans.push_back(root2->data);
               root2 = root2->right;
               s2.pop();
           }
           else break;
       }
       return ans;
    }
};