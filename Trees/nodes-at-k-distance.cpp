set<int> dis(Node *root, int k, int &count){
    if(root){
        set<int> l = dis(root->left, k, count);
        set<int> r = dis(root->right, k, count);
        set<int> cur;
        //if(both are 0 or l dose not have 0);
        if(l.count(0)==0 || r.count(0)==1)
        for(auto &i: l){
            cur.insert(i+1);
        }
        //if(both are 0 or l dose not have 0);
        if(r.count(0)==0 || l.count(0)==1)
        for(auto &i: r){
            cur.insert(i+1);
        }
        for(auto i: cur){
            if(i-1==k){
                count++;
            }
        }
        return cur;
    }
    else {
        set<int> cur;
        cur.insert(0);
        return cur;
    }
}

//Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* root, int k)
{
    int count = 0;
    dis(root,k,count);
    return count;
}