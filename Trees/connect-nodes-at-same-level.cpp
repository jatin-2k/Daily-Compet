class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           vector<Node*> temp;
           while(!q.empty()){
               temp.push_back(q.front());
               q.pop();
           }
          for(int i=0; i<temp.size()-1; i++){
              temp[i]->nextRight = temp[i+1];
          }
          for(auto i: temp){
              if(i->left)q.push(i->left);
              if(i->right)q.push(i->right);
          }
       }
    }
};