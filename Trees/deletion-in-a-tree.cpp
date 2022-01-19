node* del(node *root, int x){
	if(!root) return NULL;
	if(root->val == x){
		if(root->left){ 
			root->val = root->left->val;
			root->left = del(root->left, root->left->val);
			return root;
		}
		if(root->right){
			root->val = root->right->val;
			root->right = del(root->right, root->right->val);
			return root;
		}
		else return NULL;
	}
	else{
		root->left = del(root->left, x);
		root->right = del(root->right, x);
		return root;
	}
}