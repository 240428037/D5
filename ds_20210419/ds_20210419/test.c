//#define _CRT_SECURE_NO_WARNINGS 1
///*
//struct ListNode {
//int val;
//struct ListNode *next;
//ListNode(int x) : val(x), next(NULL) {}
//};*/
//typedef struct ListNode ListNode;
//class Partition {
//public:
//	ListNode* partition(ListNode* pHead, int x) {
//		// write code here
//		ListNode*lesshead, *lesstail;
//		ListNode*greaterhead, *greatertail;
//		lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
//		greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
//		lesshead->next = greaterhead->next = NULL;
//		ListNode*cur = pHead;
//		while (cur)
//		{
//			if (cur->val<x)
//			{
//				lesstail->next = cur;
//				lesstail = lesstail->next;
//			}
//			else
//			{
//				greatertail->next = cur;
//				greatertail = greatertail->next;
//			}
//			cur = cur->next;
//		}
//		lesstail->next = greaterhead->next;
//		greatertail->next = NULL;
//		ListNode*list = lesshead->next;
//		free(lesshead);
//		free(greaterhead);
//		return list;
//	}
//};


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

//����˼·��
//���������������ͷ�ڵ��β�ڵ�
//lesshead,lesstail
//greaterhead,greatertail
//�ٶ���һ��ָ��cur=head,����ȥ����������
//cur->val��x��һ���бȽ�
//��xС�Ľڵ��õ�lessβ��
//��x��Ľڵ��õ�greaterβ��
//Ȼ���greater�����ͷ�ڵ����ӵ�less�����β�ڵ�
//����greatertail->next=NULL;
//����һ��list=lesshead ���return list
//����ͷŵ�lesshead��greaterhead
//1 4 3 2 5 2  x=3
//1 2 2 4 3 5
struct ListNode* partition(struct ListNode* head, int x){
	//����lesshead,lesstail,greaterhead,greatertail������ֵ
	struct ListNode*lesshead, *lesstail;
	struct ListNode*greaterhead, *greatertail;
	//Ϊ���ĸ��ڵ㿪�ռ�
	lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));
	//��ʼ��lesshead,greaterheadA
	lesshead->next = greaterhead->next = NULL;
	//����cur=head������ȥ����������
	struct ListNode*cur = head;
	while (cur)
	{
		//��xС��β�嵽lesstail
		if (cur->val<x)
		{
			lesstail->next = cur;
			lesstail = lesstail->next;
			cur = cur->next;
		}
		//>=x,β�嵽greatertail
		else
		{
			greatertail->next = cur;
			greatertail = greatertail->next;
			cur = cur->next;
		}
	}
	//greater��ͷ�ڵ����ӵ�less��β�ڵ�
	//greaterβ�ڵ�ָ���
	//list=lesshead
	//�ͷŵ�lesshead��greaterhead
	lesstail->next = greaterhead->next;
	greatertail->next = NULL;
	struct ListNode*list = lesshead->next;
	free(lesshead);
	free(greaterhead);
	return list;
}







/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
//ͷ�巨
typedef struct ListNode Node;
//����Ҫ���淽��-����һ��
//if(head==NULL||head->next==NULL)
//  return head;
//����ǿսڵ�
//cur=head=NULL;
//while(cur)ѭ���ͽ���ȥ
//���return newhead=NULL;
//���ֻ��һ���ڵ㣬������ͷ��Ϳ���
struct ListNode* reverseList(struct ListNode* head){
	//��������ָ��newhead cur next;
	//����newhead��������cur,next����������
	//�ֱ�ָ��NULL,head,cur->next;
	Node*newhead = NULL, *cur = head;
	//��ֹ������curָ��NULL
	//����ѭ������������cur!=NULL
	//��while(cur)
	while (cur)
	{
		//һ����curָ���Ԫ������������ȥ��
		//cur��cur->next��ʧȥ��ϵ��
		//������Ҫ����next=cur->next;
		//���next=cur->nextӦ�÷���ѭ���������ͷ��֮ǰ
		Node*next = cur->next;
		//ͷ��
		//���������cur->next=newhead
		//��һ��curָ��NULL
		//�Ժ�ÿ��cur�ŵ���������Ҫָ���ϴε����һ���ڵ�
		cur->next = newhead;
		//�����������cur��newhead;
		newhead = cur;
		//���������Ϊ��ʹcur��next����������
		cur = next;
	}
	//��󷵻��������ͷ�ڵ�Ϳ�
	return newhead;
}
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		ListNode*slow = A;
		ListNode*fast = A;
		ListNode*prev = NULL;
		while (fast&&fast->next)
		{
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = NULL;
		slow = reverseList(slow);
		while (A)
		{
			if (A->val != slow->val)
			{
				return false;
			}
			else
			{
				A = A->next;
				slow = slow->next;
			}
		}
		return true;
	}
};




bool isPalindrome(struct ListNode* head){
	struct ListNode*prev = NULL, *slow = head, *fast = head;
	while (fast&&fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	struct ListNode*newhead = NULL, *cur = slow;
	while (cur)
	{
		struct ListNode*next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	while (head)
	{
		if (head->val != slow)
			return false;
		else
		{
			head = head->next;
			slow = slow->next;
		}
	}
	return true;
}