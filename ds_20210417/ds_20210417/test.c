//////#define _CRT_SECURE_NO_WARNINGS 1
///////**
//////* Definition for singly-linked list.
//////* struct ListNode {
//////*     int val;
//////*     struct ListNode *next;
//////* };
//////*/
//////
////////定义一个新链表
////////取两个链表中小的节点，拿下来尾插
//////typedef struct ListNode Node;
//////struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//////	//如果l1为空就返回l2
//////	if (l1 == NULL)
//////		return l2;
//////	//如果l2为空就返回l1
//////	if (l2 == NULL)
//////		return l1;
//////	//定义一个新链表的头节点head和尾节点tail
//////	//最开始head=tail=NULL
//////	Node*head = NULL, *tail = NULL;
//////	//先在l1和l2中拿一个小的，放到新链表中
//////	//此时新链表的头节点和尾节点都等于这个值
//////	//如果l1->val<l2->val
//////	//拿l1的节点下来
//////	//然后l1=l1->next;
//////	if (l1->val<l2->val)
//////	{
//////		head = tail = l1;
//////		l1 = l1->next;
//////	}
//////	//否则，拿l2的节点下来
//////	//然后l2=l2->next;
//////	//如果l1和l2的值相等
//////	//不会进入if，那么就会进入else
//////	//其实就是两个相等，拿哪个下来都一样，此时就拿了l2的下来
//////	else
//////	{
//////		head = tail = l2;
//////		l2 = l2->next;
//////	}
//////	//取小的尾插
//////	//当l1走完或者l2走完while循环就终止
//////	//所以while的循环控制条件是l1!=NULL&&l2!=NULL
//////	while (l1&&l2)
//////	{
//////		//如果l1->val<l2->val
//////		//拿l1下来尾插
//////		//即tail->next=l1;
//////		//然后l1往后走
//////		//l1->l1->next
//////		if (l1->val<l2->val)
//////		{
//////			tail->next = l1;
//////			l1 = l1->next;
//////		}
//////		//和上述逻辑一样
//////		else
//////		{
//////			tail->next = l2;
//////			l2 = l2->next;
//////		}
//////		//到这里，肯定是l1或者l2中有一个节点被拿下来尾插了
//////		//那么tail往后走
//////		//即tail=tail->next;
//////		tail = tail->next;
//////	}
//////	//因为while的循环控制条件是l1走完或者l2走完就终止
//////	//那么到这里，肯定是l1或者l2走完了
//////	//我们不去管是l1走完了还是l2走完了
//////	//写两个while循环就好
//////	//哪个没走完就进入哪个循环，把剩下的节点依次拿下来放到新链表中
//////	while (l1)
//////	{
//////		tail->next = l1;
//////		l1 = l1->next;
//////		tail = tail->next;
//////	}
//////	while (l2)
//////	{
//////		tail->next = l2;
//////		l2 = l2->next;
//////		tail = tail->next;
//////	}
//////	//最后返回新链表的头节点
//////	return head;
//////}
//////
//////
//////
//////
////////解题思路：
////////我们可以创建一个新链表
////////让两个老链表中的节点，分别进行比较，取小的那个拿下来尾插
////////最后返回新链表的头节点
//////
//////struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//////	//一上来首先考虑特殊情况
//////	//如果l1为空，那就不用比了，直接return l2;
//////	//同理，如果l2为空，直接return l1;
//////	if (l1 == NULL)
//////		return l2;
//////	if (l2 == NULL)
//////		return l1;
//////
//////	//创建新链表的头节点head和尾节点tail
//////	//最开始两个节点都置为空
//////
//////	struct ListNode*head = NULL, *tail = NULL;
//////	//在正式开始走while循环之前，需要先进行一次if判断
//////	//取两个升序链表中一个较小的节点，拿下来尾插
//////	//使得新链表不为空
//////	//否则，head为空，接下来尾插到tail->next,那么新链表的头节点始终是空的
//////	if (l1->val < l2->val)
//////	{
//////		head = tail = l1;
//////		l1 = l1->next;
//////	}
//////	else
//////	{
//////		head = tail = l2;
//////		l2 = l2->next;
//////	}
//////
//////	//只要l1和l2有一个走完，循环就结束
//////	//所以while的循环控制条件是l1!=NULL&&l2!=NULL
//////	while (l1&&l2)
//////	{
//////		if (l1->val < l2->val)
//////		{
//////			tail->next = l1;
//////			l1 = l1->next;
//////		}
//////		else
//////		{
//////			tail->next = l2;
//////			l2 = l2->next;
//////		}
//////		tail = tail->next;
//////	}
//////
//////	//走到这，l1和l2中必然有一个走完了
//////	//我们也不知道哪个走完了
//////	//那么写两个while循环，让没走完的那个链表进入循环就好
//////	while (l1)
//////	{
//////		tail->next = l1;
//////		l1 = l1->next;
//////		tail = tail->next;
//////	}
//////	while (l2)
//////	{
//////		tail->next = l2;
//////		l2 = l2->next;
//////		tail = tail->next;
//////	}
//////	//最后返回新链表的头节点
//////	return head;
//////}
//////
//////
//////
//////
////////解题思路：
////////快慢指针
////////快指针先走k步，然后快慢指针一起走，等快指针指向空，此时慢指针指向的节点，就是倒数第k个节点
////////假设链表为
////////  1->2->3->4->5 k=1
////////slow fast
////////fast先走一步
////////然后slow和fast一起走
////////等fast指向空
////////slow正好指向5
//////struct ListNode* getKthFromEnd(struct ListNode* head, int k){
//////
//////	//一上来就考虑特殊情况，如果链表为空，或者链表只有一个节点
//////	//return head;
//////	if (head == NULL || head->next == NULL)
//////		return head;
//////
//////	//定义快慢指针，最开始*slow=*fast=head;
//////	struct ListNode*slow = head, *fast = head;
//////
//////	//让fast先走k步
//////	//得考虑一个特殊情况
//////	//如果k的值大于链表的长度，return NULL
//////	while (k--)
//////	{
//////		if (fast)
//////			fast = fast->next;
//////		else
//////			return NULL;
//////	}
//////
//////	//fast走了k步以后，slow和fast一起走
//////	while (fast)
//////	{
//////		slow = slow->next;
//////		fast = fast->next;
//////	}
//////
//////	//最后return slow;
//////	return slow;
//////}
//////
//////
//////
//////
//////
///////**
//////* Definition for singly-linked list.
//////* struct ListNode {
//////*     int val;
//////*     struct ListNode *next;
//////* };
//////*/
//////
////////解题思路：
////////快慢指针
////////快指针先走k步，然后快慢指针一起走，等快指针指向空，此时慢指针指向的节点，就是倒数第k个节点
////////假设链表为
////////  1->2->3->4->5 k=1
////////slow fast
////////fast先走一步
////////然后slow和fast一起走
////////等fast指向空
////////slow正好指向5
//////
//////
//////struct ListNode* getKthFromEnd(struct ListNode* head, int k){
//////
//////	//一上来就考虑特殊情况，如果链表为空，或者链表只有一个节点
//////	//return head;
//////	if (head == NULL || head->next == NULL)
//////		return head;
//////
//////	//定义快慢指针，最开始*slow=*fast=head;
//////	struct ListNode*slow = head, *fast = head;
//////
//////	//让fast先走k步
//////	//得考虑一个特殊情况
//////	//如果k的值大于链表的长度，return NULL
//////	while (k--)
//////	{
//////		if (fast)
//////			fast = fast->next;
//////		else
//////			return NULL;
//////	}
//////
//////	//fast走了k步以后，slow和fast一起走
//////	while (fast)
//////	{
//////		slow = slow->next;
//////		fast = fast->next;
//////	}
//////
//////	//最后return slow;
//////	return slow;
//////}
////
////
////
////
//////逆方向-迭代
////typedef struct ListNode Node;
////struct ListNode* reverseList(struct ListNode* head){
////	//如果头节点为空，或者只有一个头节点没有其他结点
////	//return head就行
////	if (head == NULL || head->next == NULL)
////		return head;
////	//定义三个指针：n1,n2,n3;
////	//开始时分别指向NULL,head,head->next;
////	Node*n1 = NULL, *n2 = head, *n3 = head->next;
////	//终止条件是n1指向最后一个节点，n2,n3指向NULL
////	//所以循环控制条件是n2!=NULL
////	//即while(n2)
////	while (n2)
////	{
////		//反转
////		n2->next = n1;
////		//迭代
////		n1 = n2;
////		//n3给n2要加判断条件
////		//如果n3已经指向NULL，就不能把NULL给n2
////		n2 = n3;
////		if (n3)
////			n3 = n3->next;
////
////
////	}
////	return n1;
////}
////
////
//////头插法
////typedef struct ListNode Node;
//////不需要像逆方向-迭代一样
//////if(head==NULL||head->next==NULL)
//////  return head;
//////如果是空节点
//////cur=head=NULL;
//////while(cur)循环就进不去
//////最后return newhead=NULL;
//////如果只有一个节点，拿下来头插就可以
////struct ListNode* reverseList(struct ListNode* head){
////	//定义三个指针newhead cur next;
////	//其中newhead是新链表，cur,next在老链表里
////	//分别指向NULL,head,cur->next;
////	Node*newhead = NULL, *cur = head;
////	//终止条件是cur指向NULL
////	//所以循环控制条件是cur!=NULL
////	//即while(cur)
////	while (cur)
////	{
////		//一旦把cur指向的元素往新链表里去放
////		//cur和cur->next就失去联系了
////		//所以需要定义next=cur->next;
////		//这个next=cur->next应该放在循环里，并且在头插之前
////		Node*next = cur->next;
////		//头插
////		//在新链表里，cur->next=newhead
////		//第一次cur指向NULL
////		//以后每次cur放到新链表里要指向上次的最后一个节点
////		cur->next = newhead;
////		//在新链表里，把cur给newhead;
////		newhead = cur;
////		//在老链表里，为了使cur和next继续往后走
////		cur = next;
////	}
////	//最后返回新链表的头节点就可
////	return newhead;
////}
////
////
////
/////**
////* Definition for singly-linked list.
////* struct ListNode {
////*     int val;
////*     struct ListNode *next;
////* };
////*/
////
////////解题思路：
////////逆方向
////////迭代
////////初始：
////////NULL 1->2->NULL
////////n1  n2 n3
////////第一次循环：
////////NULL<-1->2->NULL -反转
////////     n1 n2  n3   -迭代   n3->next要加判断条件if(n3)
////////第二次循环：
////////NULL<-1<-2->NULL -反转
////////        n1  n2   -迭代   while循环控制条件为n2!=NULL
////////最后return n1就行反转后链表的头节点
////////2->1->NULL
//////struct ListNode* reverseList(struct ListNode* head){
//////	//一上来就先判断特殊情况，如果链表为空，或者链表只有一个节点
//////	//return head;就行吧，不用反转了
//////	if (head == NULL || head->next == NULL)
//////		return head;
//////	//定义三个指针n1,n2,n3
//////	//最开始分别指向NULL,head,head->next
//////	struct ListNode*n1 = NULL, *n2 = head, *n3 = head->next;
//////	//当n2!=NULL才需要迭代 
//////	//n2==NULL return n1就行，因为此时链表已经反转过来了
//////	while (n2)
//////	{
//////		n2->next = n1;
//////		n1 = n2;
//////		n2 = n3;
//////		//n3=n3->next要加判断条件
//////		//当n3==NULL
//////		//n3就没有必要再往后继续走了
//////		if (n3)
//////			n3 = n3->next;
//////	}
//////	//反转后链表的头节点为n1;
//////	return n1;
//////}
////
////
////
////
/////**
////* Definition for singly-linked list.
////* struct ListNode {
////*     int val;
////*     struct ListNode *next;
////* };
////*/
////
//////解题思路：
//////逆方向
//////迭代
//////初始：
//////NULL 1->2->NULL
//////n1  n2 n3
//////第一次循环：
//////NULL<-1->2->NULL -反转
//////     n1 n2  n3   -迭代   n3->next要加判断条件if(n3)
//////第二次循环：
//////NULL<-1<-2->NULL -反转
//////        n1  n2   -迭代   while循环控制条件为n2!=NULL
//////最后return n1就行反转后链表的头节点
//////2->1->NULL
////struct ListNode* reverseList(struct ListNode* head){
////	//一上来就先判断特殊情况，如果链表为空，或者链表只有一个节点
////	//return head;就行吧，不用反转了
////	if (head == NULL || head->next == NULL)
////		return head;
////	//定义三个指针n1,n2,n3
////	//最开始分别指向NULL,head,head->next
////	struct ListNode*n1 = NULL, *n2 = head, *n3 = head->next;
////	//当n2!=NULL才需要迭代 
////	//n2==NULL return n1就行，因为此时链表已经反转过来了
////	while (n2)
////	{
////		//-反转
////		n2->next = n1;
////		//-迭代
////		n1 = n2;
////		n2 = n3;
////		//n3=n3->next要加判断条件
////		//当n3==NULL
////		//n3就没有必要再往后继续走了
////		if (n3)
////			n3 = n3->next;
////	}
////	//反转后链表的头节点为n1;
////	return n1;
////}
////
////
//
//
//
////头插法
//typedef struct ListNode Node;
////不需要像逆方向-迭代一样
////if(head==NULL||head->next==NULL)
////  return head;
////如果是空节点
////cur=head=NULL;
////while(cur)循环就进不去
////最后return newhead=NULL;
////如果只有一个节点，拿下来头插就可以
//struct ListNode* reverseList(struct ListNode* head){
//	//定义三个指针newhead cur next;
//	//其中newhead是新链表，cur,next在老链表里
//	//分别指向NULL,head,cur->next;
//	Node*newhead = NULL, *cur = head;
//	//终止条件是cur指向NULL
//	//所以循环控制条件是cur!=NULL
//	//即while(cur)
//	while (cur)
//	{
//		//一旦把cur指向的元素往新链表里去放
//		//cur和cur->next就失去联系了
//		//所以需要定义next=cur->next;
//		//这个next=cur->next应该放在循环里，并且在头插之前
//		Node*next = cur->next;
//		//头插
//		//在新链表里，cur->next=newhead
//		//第一次cur指向NULL
//		//以后每次cur放到新链表里要指向上次的最后一个节点
//		cur->next = newhead;
//		//在新链表里，把cur给newhead;
//		newhead = cur;
//		//在老链表里，为了使cur和next继续往后走
//		cur = next;
//	}
//	//最后返回新链表的头节点就可
//	return newhead;
//}


//解题思路:
//头插法
//定义一个新链表
//把老链表里的节点拿下来头插
//第一次循环：
//老链表：
//  1->2->NULL      -next=cur->next;
//cur next
//新链表：
//newhead=NULL
//newhead=NULL<-1=cur   -cur->next=newhead;
//NULL<-1=newhead       -newhead=cur;
//老链表：
//1->2>NULL
// cur/next      -cur=next;
//第二次循环：
//老链表：
//1->2->NULL
//   cur next     -next=cur->next
//新链表：
//NULL<-1=newhead<-2=cur   -cur->next=newhead
//NULL<-1<-2=newahead   -newhead=cur;
//老链表:
//1->2->NULL
//     cur/next  -cur=next;
//此时cur==NULL,不会进入第三次循环
//在新链表里，头插已经全部完成，return newhead就行

//使用头插法完成反转链表
//不同考虑head==NULL或者head->next==NULL
//如果head==NULL，即cur=NULL,不会进入while循环，直接return newhead=NULL;
//如果head->next==NULL 进入while循环 头插一个节点后 return newhead就行
struct ListNode* reverseList(struct ListNode* head){
	//定义一个新链表的头节点newhead
	//最开始让newhead=NULL
	//定义一个cur,最开始让它指向head
	struct ListNode*newhead = NULL, *cur = head;
	//循环控制条件是cur!=NULL
	//当cur==NULL，头插已经全部完成，return newhead;
	while (cur)
	{
		//需要在定义一个next=cur->next;
		//否则cur拿到新链表去头插的时候，cur和cur->next就会失去联系
		//老链表：
		struct ListNode*next = cur->next;
		//新链表：
		cur->next = newhead;
		newhead = cur;
		//老链表：
		cur = next;
	}
	//返回新链表的头节点
	return newhead;
}


typedef struct ListNode Node;
struct ListNode* removeElements(struct ListNode* head, int val){
	//双指针
	//定义两个指针prev cur
	//最初始的情况的是prev=NULL,cur=head;
	Node*prev = NULL, *cur = head;
	//结束的情况时prev指向最后一个元素，cur指向NULL
	//所以循环控制条件为cur
	while (cur)
	{
		//如果cur->val==val
		//就要删除掉这个元素
		//prev cur
		// 1    6    2   3
		//prev->next=cur->next
		//删除这个元素
		//free(cur);
		//然后再把cur=prev->next;
		if (cur->val == val)
		{
			//如果第一个节点就是val呢？
			//此时prev=NULL;
			//没法按照prev->next=cur->next;free(cur);cur=prev->next;这个逻辑去删除这个节点
			//所以
			//if的条件既可以是cur==head也可以是prev==NULL
			//此时
			//重新定义头节点：head=cur->next
			//然后删除掉这个元素： free(cur);
			//再把head赋给cur:cur=head;
			if (cur == head)//if(prev=NULL)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;//必须有这一步
				//如果最后一个数是val，程序要走到prev指向最后一个数时才算结束
				//这个时候，while的循环判断条件里的cur是一个野指针
				//所以要把cur置为NULL,即cur=prev->next
				//删除了val后,prev->next为NULL
			}


		}
		//如果cur->val!=val就要两个指针一起向后走
		//把cur给prev,然后cur往后走
		//prev=cur;
		//cur=cur->next;
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	//题目要求返回新的头节点-return head;
	return head;
}


//解题思路
//遍历链表如果有和val相同的节点就free掉
//然后返回删除后的链表头节点
//双指针
//如果只有一个指针cur
//cur->val==val
//free(cur)之后，cur和cur->next就失去了联系

struct ListNode* deleteNode(struct ListNode* head, int val){
	//定义prev和cur两个指针
	//最开始*prev=NULL，*cur=head;
	struct ListNode*prev = NULL, *cur = head;
	//当cur==NULL循环结束
	while (cur)
	{
		//cur->val==val:删节点
		if (cur->val == val)
		{
			//如果head==val,就要重新定义头节点
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head->next;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		//cur->val!=val
		//两个指针继续往后走
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	//返回删除之后链表的头节点
	return head;
}