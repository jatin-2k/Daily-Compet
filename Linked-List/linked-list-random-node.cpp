class Solution {
public:
    vector<int> nodes;
    int n;
    Solution(ListNode* h) {
        while(h){
            nodes.push_back(h->val);
            h = h->next;
        }
        n = nodes.size();
    }
    
    int getRandom() {
        return nodes[rand()%n];
    }
};