class Solution {
public:
	TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder, int&prei, int inbegin, int inend){
		if (inbegin > inend){
			return nullptr;
		}
		TreeNode*root = new TreeNode(preorder[prei]);
		int rooti = inbegin;
		while (rooti != inend){
			if (inorder[rooti] == preorder[prei]){
				break;
			}
			else{
				rooti++;
			}
		}
		//[inbegin,rooti-1]rooti[rooti+1,inend]
		if (inbegin <= rooti - 1){
			root->left = buildTree1(preorder, inorder, ++prei, inbegin, rooti - 1);
		}
		else{
			root->left = nullptr;
		}
		if (rooti + 1 <= inend){
			root->right = buildTree1(preorder, inorder, ++prei, rooti + 1, inend);
		}
		else{
			root->right = nullptr;
		}
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int prei = 0;
		int inbegin = 0, inend = inorder.size() - 1;
		return buildTree1(preorder, inorder, prei, inbegin, inend);
	}
};




class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*>st;//存节点
		vector<int>v;//存值 v.push_back(cur->val)
		TreeNode*cur = root;
		//循环控制条件cur||st
		while (cur != nullptr || !st.empty()){
			//1.访问左路节点 左路节点入栈
			while (cur != nullptr){
				st.push(cur);
				v.push_back(cur->val);
				cur = cur->left;
			}
			//取栈中节点 访问他的右子树
			TreeNode*top = st.top();
			st.pop();
			cur = top->right;
		}
		return v;
	}
};



class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		if (root == nullptr){
			return true;
		}
		if (root->left&&root->val != root->left->val){
			return false;
		}
		if (root->right&&root->val != root->right->val){
			return false;
		}
		return isUnivalTree(root->left) && isUnivalTree(root->right);
	}
};



class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr){
			return nullptr;
		}
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};



class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr){
			return nullptr;
		}
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};





class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr&&q == nullptr){
			return true;
		}
		if (p == nullptr || q == nullptr){
			return false;
		}
		if (p->val != q->val){
			return false;
		}
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};




class Solution {
public:
	bool issametree(TreeNode*p, TreeNode*q){
		if (p == nullptr&&q == nullptr){
			return true;
		}
		if (p == nullptr || q == nullptr){
			return false;
		}
		if (p->val != q->val){
			return false;
		}
		return issametree(p->left, q->right) && issametree(p->right, q->left);
	}
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr){
			return false;
		}
		return issametree(root->left, root->right);
	}
};




class Solution {
public:
	TreeNode*inverttree(TreeNode*root){
		if (root == nullptr){
			return nullptr;
		}
		swap(root->left, root->right);
		inverttree(root->left);
		inverttree(root->right);
		return root;
	}
	bool issametree(TreeNode*p, TreeNode*q){
		if (p == nullptr&&q == nullptr){
			return true;
		}
		if (p == nullptr || q == nullptr){
			return false;
		}
		if (p->val != q->val){
			return false;
		}
		return issametree(p->left, q->left) && issametree(p->right, q->right);
	}
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr){
			return true;
		}
		inverttree(root->left);
		return issametree(root->left, root->right);
	}
};


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL&&q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (p->val != q->val)
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
	if (root == NULL)
		return false;
	if (isSameTree(root, subRoot))
		return true;
	return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}



class Solution {
public:
	bool issametree(TreeNode*p, TreeNode*q){
		if (p == nullptr&&q == nullptr){
			return true;
		}
		if (p == nullptr || q == nullptr){
			return false;
		}
		if (p->val != q->val){
			return false;
		}
		return issametree(p->left, q->left) && issametree(p->right, q->right);
	}
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (root == nullptr){
			return false;
		}
		if (issametree(root, subRoot)){
			return true;
		}
		return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
	}
};