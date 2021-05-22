typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int treesize(TreeNode*root){
	if (root == nullptr)
}
int treeleafsize(TreeNode*root){

}
int treelevelksize(TreeNode*root, int k){

}




int TreeSize(struct TreeNode*root)
{
	if (root == NULL)
		return 0;
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}
void _preorderTraversal(struct TreeNode*root, int*retA, int*pi)
{
	if (root == NULL)
		return;
	retA[*pi] = root->val;
	(*pi)++;
	_preorderTraversal(root->left, retA, pi);
	_preorderTraversal(root->right, retA, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int size = TreeSize(root);
	int*retA = malloc(sizeof(int)*size);
	int i = 0;
	_preorderTraversal(root, retA, &i);
	*returnSize = size;
	return retA;
}

class Solution {
public:
	void preorder(TreeNode *root, vector<int> &res) {
		if (root == nullptr) {
			return;
		}
		res.push_back(root->val);
		preorder(root->left, res);
		preorder(root->right, res);
	}

	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		preorder(root, res);
		return res;
	}
};

class Solution {
public:
	void pre
	vector<int> preorderTraversal(TreeNode* root) {

	}
};


class Solution {
public:
	void preorder(TreeNode*root, vector<int>&v){
		if (root == nullptr){
			return;
		}
		v.push_back(root->val);
		preorder(root->left, v);
		preorder(root->right, v);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int>v;
		preorder(root, v);
		return v;
	}
};


class Solution {
public:
	void inorder(TreeNode* root, vector<int>& res) {
		if (!root) {
			return;
		}
		inorder(root->left, res);
		res.push_back(root->val);
		inorder(root->right, res);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		return res;
	}
};


class Solution {
public:
	void postorder(TreeNode*root, vector<int>&v){
		if (root == nullptr){
			return;
		}
		postorder(root->left, v);
		postorder(root->right, v);
		v.push_back(root->val);

	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int>v;
		postorder(root, v);
		return v;
	}
};