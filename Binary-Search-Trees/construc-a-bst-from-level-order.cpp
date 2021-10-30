struct NodeDetails
{
    Node *ptr;
    int min, max;
};

//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    // base case
    if (n == 0)
        return NULL;
    Node *root;
    
    //using a queue to store NodeDetails of a node. 
    queue<NodeDetails> q;
    
    int i=0;
    
    //node details for the root of the BST.
    NodeDetails newNode;
    newNode.ptr = new Node(arr[i++]);
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    q.push(newNode);
    
    //getting the root of the BST
    root = newNode.ptr;
    
    while (i != n)     
    {
        //extracting NodeDetails of a node from the queue.
        NodeDetails temp = q.front();
        q.pop();
        
        //checking whether there are more elements in the arr[] and arr[i] 
        //can be left child of 'temp.ptr' or not.
        if (i<n&&(arr[i]<temp.ptr->data&&arr[i]>temp.min))
        {
            //creating NodeDetails for new node and adding it to the queue.
            newNode.ptr = new Node(arr[i++]);
            newNode.min = temp.min;
            newNode.max = temp.ptr->data;
            q.push(newNode);
            
            //making this 'newNode' as left child of 'temp.ptr'.
            temp.ptr->left = newNode.ptr;         
        }
        
        //checking whether there are more elements in the arr[] and arr[i] 
        //can be right child of 'temp.ptr' or not.
        if (i<n&&(arr[i]>temp.ptr->data&&arr[i]<temp.max))
        {
            //creating NodeDetails for new node and adding it to the queue.
            newNode.ptr = new Node(arr[i++]);
            newNode.min = temp.ptr->data;
            newNode.max = temp.max;
            q.push(newNode);
            
            //making this 'newNode' as right child of 'temp.ptr'.
            temp.ptr->right = newNode.ptr;
        }     
    }
    //returning root of the required BST.
    return root;
}