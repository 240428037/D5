#define _CRT_SECURE_NO_WARNINGS 1
//定义两个新链表，
//如果val比x小，就对less链表尾插
//如果val比x大，就对greater链表尾插
//最后把less链表的尾链到greater链表的头，再返回less链表的头节点就可
typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x){
	//定义less链表的头节点和尾节点
	ListNode*lesshead, *lesstail;
	//定义greater链表的头节点和为节点
	ListNode*greaterhead, *greatertail;
	//分别为less和greater链表动态开辟空间
	lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
	greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
	//让两个链表的头节点指向NULL
	lesshead->next = greaterhead->next = NULL;
	//定义一个cur指针最开始指向head,然它在老链表里往后遍历比较
	ListNode*cur = head;
	//当cur指向NULL,也就是走到了老链表的尽头，此时循环终止
	while (cur)
	{
		//如果cur->val<x
		//把cur尾插到less链表
		if (cur->val < x)
		{
			lesstail->next = cur;
			lesstail = lesstail->next;
		}
		//如果cur->val>=x
		//把cur尾插到greater链表
		else
		{
			greatertail->next = cur;
			greatertail = greatertail->next;
		}
		//cur继续向后遍历
		cur = cur->next;
	}
	//让less链表的尾链到greater链表的头
	lesstail->next = greaterhead->next;
	//让greater链表的尾指向NULL
	//防止链表成环
	greatertail->next = NULL;
	//定义一个list指针指向less链表的头节点
	ListNode*list = lesshead->next;
	//free掉less和greater链表的头节点
	free(lesshead);
	free(greaterhead);
	//最后return新链表
	return list;
}



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



