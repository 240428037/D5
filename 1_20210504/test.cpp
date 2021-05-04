typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);



void BinaryTreeLevelOrder(BTNode* root)
{

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


int TreeSize(struct TreeNode*root)
{
	if (root == NULL)
		return 0;
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}
void _inorderTraversal(struct TreeNode*root, int*retA, int*pi)
{
	if (root == NULL)
		return;
	_inorderTraversal(root->left, retA, pi);
	retA[(*pi)++] = root->val;
	_inorderTraversal(root->right, retA, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int size = TreeSize(root);
	int*retA = malloc(sizeof(int)*size);
	int i = 0;
	_inorderTraversal(root, retA, &i);
	*returnSize = size;
	return retA;
}



int TreeSize(struct TreeNode*root)
{
	if (root == NULL)
		return 0;
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}
void _postorderTraversal(struct TreeNode*root, int*retA, int*pi)
{
	if (root == NULL)
		return;
	_postorderTraversal(root->left, retA, pi);
	_postorderTraversal(root->right, retA, pi);
	retA[(*pi)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
	int size = TreeSize(root);
	int*retA = malloc(sizeof(int)*size);
	int i = 0;
	_postorderTraversal(root, retA, &i);
	*returnSize = size;
	return retA;
}