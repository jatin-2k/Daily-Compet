int maxEnvey(){
	int n,m,c;
	cin>>n>>m;
	int max =0;
	priority_queue<int> q;
	for(int i=0; i<m; i++){
		cin>>c;
		q.push(c);
	}
	while(q.size()<n){
		int t = q.top();
		q.pop();
		if(t%2==0){
			q.push(t/2); q.push(t/2);
		}
		else{
			q.push(t/2); q.push(t/2 + 1);
		}
	}
	return q.top();
}