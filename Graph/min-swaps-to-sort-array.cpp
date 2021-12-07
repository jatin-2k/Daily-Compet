
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&arr)
	{
	    map<int,int> oldPos;
	    for(int i=0; i<arr.size(); i++){
	        oldPos[arr[i]] = i;
	    }
	    sort(arr.begin(), arr.end());
	    vector<int> adj[arr.size()];
	    for(int i=0; i<arr.size(); i++){
	        adj[oldPos[arr[i]]].push_back(i);
	    }
	   // for(int i=0; i<arr.size(); i++){
	   //     cout<<i<<"-> ";
	   //     for(auto j: adj[i]){
	   //         cout<<j<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    return calc(adj, arr.size());
	}
	
	int calc(vector<int> adj[], int V){
	    vector<bool> visited(V,0);
	    int ans=0;
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            //cout<<"From:"<<i;
	            int n = calcNodes(i, adj, visited) - 1;
	            //cout<<"="<<n<<endl;
	            ans+=n;
	        }
	    }
	    return ans;
	}
	
	int calcNodes(int i,vector<int> adj[], vector<bool>& visited){
	    visited[i]=1;
	    queue<int> q;
	    q.push(i);
	    int ans = 0;
	    while(!q.empty()){
	        int cur = q.front();
	        for(auto j: adj[cur]){
	            if(!visited[j]){
	                visited[j] = 1;
	                q.push(j);
	            }
	        }
	        q.pop();
	        ans++;
	    }
	    return ans;
	}
};
