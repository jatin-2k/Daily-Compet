class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        int i=0;
        while(!q.empty()){
            queue<Node*> temp;
            Node *last = nullptr;
            while(!q.empty()){
                Node *cur = q.front(); q.pop();
                if(last) last -> next = cur;
                temp.push(cur);
                last = cur;
            }
            while(!temp.empty()){
                if(temp.front()->left) q.push(temp.front()->left);
                if(temp.front()->right) q.push(temp.front()->right);
                temp.pop();
            }
            i++;
        }
        return root;
    }
};