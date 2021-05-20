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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int>v;
		stack<TreeNode*>st;
		TreeNode*cur = root;
		while (cur || !st.empty()){
			//1.������·�ڵ� ��·�ڵ���ջ
			while (cur != nullptr){
				st.push(cur);
				v.push_back(cur->val);
				cur = cur->left;
			}
			//2.ȡջ�еĽڵ��������������
			TreeNode*top = st.top();
			st.pop();
			cur = top->right;
		}
		return v;
	}
};