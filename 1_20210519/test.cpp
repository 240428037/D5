class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr){
			return 0;
		}
		int leftdepth = maxDepth(root->left);
		int rightdepth = maxDepth(root->right);
		return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
	}
};




class Solution {
public:
	int maxdepth(TreeNode* root){
		if (root == nullptr){
			return 0;
		}
		int leftdepth = maxdepth(root->left);
		int rightdepth = maxdepth(root->right);
		return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr){
			return true;
		}
		int leftdepth = maxdepth(root->left);
		int rightdepth = maxdepth(root->right);
		return abs(leftdepth - rightdepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
};


//
//*
//* Definition for a binary tree node.
//* struct TreeNode {
//	*int val;
//	*TreeNode *left;
//	*TreeNode *right;
//	*TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	*TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	*TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//	*
//};




/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	TreeNode* buildTree1(vector<int>&preorder, vector<int>&inorder, int&prei, int inbegin, int inend){
		if (inbegin>inend){
			return nullptr;
		}
		//1.构建根
		TreeNode*root = new TreeNode(preorder[prei]);
		//2.分割中序
		int rooti = inbegin;
		while (rooti != inend){
			if (preorder[prei] == inorder[rooti]){
				break;
			}
			else{
				rooti++;
			}
		}
		//[inbegin,rooti-1] rooti [rooti,inend]
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
		//子问题 前序确定根 中序确定左右子树区间
		//前序需要下标 中序需要区间
		return buildTree1(preorder, inorder, prei, inbegin, inend);
	}
};


class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == nullptr){
			return nullptr;
		}
		swap(root->left, root->right);
		mirrorTree(root->left);
		mirrorTree(root->right);
		return root;
	}
};




class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*>q;
		if (root){
			q.push(root);
		}
		vector<vector<int>>vv;
		while (!q.empty()){
			vector<int>v;
			int levelsize = q.size();
			for (int i = 0; i < levelsize; i++){
				TreeNode*front = q.front();
				q.pop();
				v.push_back(front->val);
				if (front->left){
					q.push(front->left);
				}
				if (front->right){
					q.push(front->right);
				}
			}
			vv.push_back(v);
		}
		return vv;
	}
};