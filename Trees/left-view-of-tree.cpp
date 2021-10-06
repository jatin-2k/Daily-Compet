int maax(Node *root, vector<int> &ans, int max,int height)
{
   // Your code here
   if(root){
       if(height > max){
           max = height;
           ans.push_back(root->data);
       }
       int l = maax(root->left, ans,max,height+1);
       int r = maax(root->right, ans,max,height+1);
       if(l<r) return l+1;
       else return r+1;
   }
   return 0;
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   int h = 0;
   int m = 0;
   maax(root, ans, h, m+1);
   return ans;
}