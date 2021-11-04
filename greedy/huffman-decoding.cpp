string decodeHuffmanData(struct MinHeapNode* root, string S)
{
    // Code here
    string s;
    MinHeapNode* temp = root;
    for(auto i: S){
        if(i=='0'){
            temp = temp -> left;
        }
        else{
            temp = temp -> right;
        }
        if(!temp->left && !temp->right){
            s+=temp->data;
            temp = root;
        }
    }
    return s;
}