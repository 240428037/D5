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

//解题思路：
//定义两个新链表的头节点和尾节点
//lesshead,lesstail
//greaterhead,greatertail
//再定义一个指针cur=head,让它去遍历老链表
//cur->val和x逐一进行比较
//比x小的节点拿到less尾插
//比x大的节点拿到greater尾插
//然后把greater链表的头节点链接到less链表的尾节点
//再让greatertail->next=NULL;
//定义一个list=lesshead 最后return list
//最后释放掉lesshead和greaterhead
//1 4 3 2 5 2  x=3
//1 2 2 4 3 5
struct ListNode* partition(struct ListNode* head, int x){
	//定义lesshead,lesstail,greaterhead,greatertail不赋初值
	struct ListNode*lesshead, *lesstail;
	struct ListNode*greaterhead, *greatertail;
	//为这四个节点开空间
	lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));
	//初始化lesshead,greaterheadA
	lesshead->next = greaterhead->next = NULL;
	//定义cur=head，让它去遍历老链表
	struct ListNode*cur = head;
	while (cur)
	{
		//比x小，尾插到lesstail
		if (cur->val<x)
		{
			lesstail->next = cur;
			lesstail = lesstail->next;
			cur = cur->next;
		}
		//>=x,尾插到greatertail
		else
		{
			greatertail->next = cur;
			greatertail = greatertail->next;
			cur = cur->next;
		}
	}
	//greater的头节点链接到less的尾节点
	//greater尾节点指向空
	//list=lesshead
	//释放掉lesshead和greaterhead
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
//头插法
typedef struct ListNode Node;
//不需要像逆方向-迭代一样
//if(head==NULL||head->next==NULL)
//  return head;
//如果是空节点
//cur=head=NULL;
//while(cur)循环就进不去
//最后return newhead=NULL;
//如果只有一个节点，拿下来头插就可以
struct ListNode* reverseList(struct ListNode* head){
	//定义三个指针newhead cur next;
	//其中newhead是新链表，cur,next在老链表里
	//分别指向NULL,head,cur->next;
	Node*newhead = NULL, *cur = head;
	//终止条件是cur指向NULL
	//所以循环控制条件是cur!=NULL
	//即while(cur)
	while (cur)
	{
		//一旦把cur指向的元素往新链表里去放
		//cur和cur->next就失去联系了
		//所以需要定义next=cur->next;
		//这个next=cur->next应该放在循环里，并且在头插之前
		Node*next = cur->next;
		//头插
		//在新链表里，cur->next=newhead
		//第一次cur指向NULL
		//以后每次cur放到新链表里要指向上次的最后一个节点
		cur->next = newhead;
		//在新链表里，把cur给newhead;
		newhead = cur;
		//在老链表里，为了使cur和next继续往后走
		cur = next;
	}
	//最后返回新链表的头节点就可
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