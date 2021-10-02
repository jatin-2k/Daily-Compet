stack<int> _push(int arr[],int n)
{
   // your code here
   stack<int> s,ans;
   int min = INT_MAX;
   for(int i=0; i<n; i++){
       s.push(arr[i]);
       if(s.top()<min){
           min = s.top();
       }
       ans.push(min);
   }
   return ans;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{
    // your code here
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}