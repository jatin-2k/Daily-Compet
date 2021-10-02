vector<string> generate(int N)
{
	queue<string> q;
	q.push("1");
	vector<string> ans;
	while(N--){
	    string s1 = q.front();
	    q.pop();
	    ans.push_back(s1);
	    q.push(s1+"0");
	    q.push(s1+"1");
	}
	return ans;
}