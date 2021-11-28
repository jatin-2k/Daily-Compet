void permuteRec(string str, int n, vector <string> &ans, int index = -1, string curr = "") 
{ 
    // base case 
    if (index == n)  
        return; 
  
    ans.push_back(curr);
    
    for (int i = index + 1; i < n; i++) { 
  
        curr += str[i]; 
        permuteRec(str, n, ans, i, curr); 
   
        // backtracking 
        curr = curr.erase(curr.size() - 1);  
    } 
    return; 
} 
//Function to return the lexicographically sorted power-set of the string.
vector <string> powerSet(string s)
{
   //Your code here
   //sort(s.begin(), s.end()); 
   vector <string> ans;
   permuteRec(s, s.size(), ans); 
   return ans;
}