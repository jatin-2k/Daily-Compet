class TimeMap {
public:
    
    map<string, vector<pair<int,string>>> mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int time) {
        mp[key].push_back({time,value});
    }
    
    string get(string key, int time) {
        if(mp.find(key) == mp.end()) return "";
        vector<pair<int,string>> &v = mp[key];
        string val = "";
        int l=0,r=v.size();
        while(l<r){
            int mid = l+(r-l)/2;
            if(v[mid].first <= time){
                l = mid+1;
            }
            else r = mid;
        }
        if(l <= 0) return "";
        return v[l-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */