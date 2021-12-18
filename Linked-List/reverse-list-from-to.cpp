class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<pair<int,ListNode*>> v;
        while(head){
            v.push_back({head->val, head});
            head = head->next;
        }
        reverse(v.begin()+left-1, v.begin()+right);
        for(auto i: v) cout<<i.second -> val<<endl;
        head = v[0].second;
        v[0].second -> next = NULL;
        for(int i=1; i<v.size(); i++){
            head -> next = v[i].second;
            v[i].second -> next = NULL;
            head = head -> next;
        }
        return v[0].second;
    }
};