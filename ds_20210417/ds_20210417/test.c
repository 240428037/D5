//////#define _CRT_SECURE_NO_WARNINGS 1
///////**
//////* Definition for singly-linked list.
//////* struct ListNode {
//////*     int val;
//////*     struct ListNode *next;
//////* };
//////*/
//////
////////����һ��������
////////ȡ����������С�Ľڵ㣬������β��
//////typedef struct ListNode Node;
//////struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//////	//���l1Ϊ�վͷ���l2
//////	if (l1 == NULL)
//////		return l2;
//////	//���l2Ϊ�վͷ���l1
//////	if (l2 == NULL)
//////		return l1;
//////	//����һ���������ͷ�ڵ�head��β�ڵ�tail
//////	//�ʼhead=tail=NULL
//////	Node*head = NULL, *tail = NULL;
//////	//����l1��l2����һ��С�ģ��ŵ���������
//////	//��ʱ�������ͷ�ڵ��β�ڵ㶼�������ֵ
//////	//���l1->val<l2->val
//////	//��l1�Ľڵ�����
//////	//Ȼ��l1=l1->next;
//////	if (l1->val<l2->val)
//////	{
//////		head = tail = l1;
//////		l1 = l1->next;
//////	}
//////	//������l2�Ľڵ�����
//////	//Ȼ��l2=l2->next;
//////	//���l1��l2��ֵ���
//////	//�������if����ô�ͻ����else
//////	//��ʵ����������ȣ����ĸ�������һ������ʱ������l2������
//////	else
//////	{
//////		head = tail = l2;
//////		l2 = l2->next;
//////	}
//////	//ȡС��β��
//////	//��l1�������l2����whileѭ������ֹ
//////	//����while��ѭ������������l1!=NULL&&l2!=NULL
//////	while (l1&&l2)
//////	{
//////		//���l1->val<l2->val
//////		//��l1����β��
//////		//��tail->next=l1;
//////		//Ȼ��l1������
//////		//l1->l1->next
//////		if (l1->val<l2->val)
//////		{
//////			tail->next = l1;
//////			l1 = l1->next;
//////		}
//////		//�������߼�һ��
//////		else
//////		{
//////			tail->next = l2;
//////			l2 = l2->next;
//////		}
//////		//������϶���l1����l2����һ���ڵ㱻������β����
//////		//��ôtail������
//////		//��tail=tail->next;
//////		tail = tail->next;
//////	}
//////	//��Ϊwhile��ѭ������������l1�������l2�������ֹ
//////	//��ô������϶���l1����l2������
//////	//���ǲ�ȥ����l1�����˻���l2������
//////	//д����whileѭ���ͺ�
//////	//�ĸ�û����ͽ����ĸ�ѭ������ʣ�µĽڵ������������ŵ���������
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
//////	//��󷵻��������ͷ�ڵ�
//////	return head;
//////}
//////
//////
//////
//////
////////����˼·��
////////���ǿ��Դ���һ��������
////////�������������еĽڵ㣬�ֱ���бȽϣ�ȡС���Ǹ�������β��
////////��󷵻��������ͷ�ڵ�
//////
//////struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//////	//һ�������ȿ����������
//////	//���l1Ϊ�գ��ǾͲ��ñ��ˣ�ֱ��return l2;
//////	//ͬ�����l2Ϊ�գ�ֱ��return l1;
//////	if (l1 == NULL)
//////		return l2;
//////	if (l2 == NULL)
//////		return l1;
//////
//////	//�����������ͷ�ڵ�head��β�ڵ�tail
//////	//�ʼ�����ڵ㶼��Ϊ��
//////
//////	struct ListNode*head = NULL, *tail = NULL;
//////	//����ʽ��ʼ��whileѭ��֮ǰ����Ҫ�Ƚ���һ��if�ж�
//////	//ȡ��������������һ����С�Ľڵ㣬������β��
//////	//ʹ��������Ϊ��
//////	//����headΪ�գ�������β�嵽tail->next,��ô�������ͷ�ڵ�ʼ���ǿյ�
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
//////	//ֻҪl1��l2��һ�����꣬ѭ���ͽ���
//////	//����while��ѭ������������l1!=NULL&&l2!=NULL
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
//////	//�ߵ��⣬l1��l2�б�Ȼ��һ��������
//////	//����Ҳ��֪���ĸ�������
//////	//��ôд����whileѭ������û������Ǹ��������ѭ���ͺ�
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
//////	//��󷵻��������ͷ�ڵ�
//////	return head;
//////}
//////
//////
//////
//////
////////����˼·��
////////����ָ��
////////��ָ������k����Ȼ�����ָ��һ���ߣ��ȿ�ָ��ָ��գ���ʱ��ָ��ָ��Ľڵ㣬���ǵ�����k���ڵ�
////////��������Ϊ
////////  1->2->3->4->5 k=1
////////slow fast
////////fast����һ��
////////Ȼ��slow��fastһ����
////////��fastָ���
////////slow����ָ��5
//////struct ListNode* getKthFromEnd(struct ListNode* head, int k){
//////
//////	//һ�����Ϳ�������������������Ϊ�գ���������ֻ��һ���ڵ�
//////	//return head;
//////	if (head == NULL || head->next == NULL)
//////		return head;
//////
//////	//�������ָ�룬�ʼ*slow=*fast=head;
//////	struct ListNode*slow = head, *fast = head;
//////
//////	//��fast����k��
//////	//�ÿ���һ���������
//////	//���k��ֵ��������ĳ��ȣ�return NULL
//////	while (k--)
//////	{
//////		if (fast)
//////			fast = fast->next;
//////		else
//////			return NULL;
//////	}
//////
//////	//fast����k���Ժ�slow��fastһ����
//////	while (fast)
//////	{
//////		slow = slow->next;
//////		fast = fast->next;
//////	}
//////
//////	//���return slow;
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
////////����˼·��
////////����ָ��
////////��ָ������k����Ȼ�����ָ��һ���ߣ��ȿ�ָ��ָ��գ���ʱ��ָ��ָ��Ľڵ㣬���ǵ�����k���ڵ�
////////��������Ϊ
////////  1->2->3->4->5 k=1
////////slow fast
////////fast����һ��
////////Ȼ��slow��fastһ����
////////��fastָ���
////////slow����ָ��5
//////
//////
//////struct ListNode* getKthFromEnd(struct ListNode* head, int k){
//////
//////	//һ�����Ϳ�������������������Ϊ�գ���������ֻ��һ���ڵ�
//////	//return head;
//////	if (head == NULL || head->next == NULL)
//////		return head;
//////
//////	//�������ָ�룬�ʼ*slow=*fast=head;
//////	struct ListNode*slow = head, *fast = head;
//////
//////	//��fast����k��
//////	//�ÿ���һ���������
//////	//���k��ֵ��������ĳ��ȣ�return NULL
//////	while (k--)
//////	{
//////		if (fast)
//////			fast = fast->next;
//////		else
//////			return NULL;
//////	}
//////
//////	//fast����k���Ժ�slow��fastһ����
//////	while (fast)
//////	{
//////		slow = slow->next;
//////		fast = fast->next;
//////	}
//////
//////	//���return slow;
//////	return slow;
//////}
////
////
////
////
//////�淽��-����
////typedef struct ListNode Node;
////struct ListNode* reverseList(struct ListNode* head){
////	//���ͷ�ڵ�Ϊ�գ�����ֻ��һ��ͷ�ڵ�û���������
////	//return head����
////	if (head == NULL || head->next == NULL)
////		return head;
////	//��������ָ�룺n1,n2,n3;
////	//��ʼʱ�ֱ�ָ��NULL,head,head->next;
////	Node*n1 = NULL, *n2 = head, *n3 = head->next;
////	//��ֹ������n1ָ�����һ���ڵ㣬n2,n3ָ��NULL
////	//����ѭ������������n2!=NULL
////	//��while(n2)
////	while (n2)
////	{
////		//��ת
////		n2->next = n1;
////		//����
////		n1 = n2;
////		//n3��n2Ҫ���ж�����
////		//���n3�Ѿ�ָ��NULL���Ͳ��ܰ�NULL��n2
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
//////ͷ�巨
////typedef struct ListNode Node;
//////����Ҫ���淽��-����һ��
//////if(head==NULL||head->next==NULL)
//////  return head;
//////����ǿսڵ�
//////cur=head=NULL;
//////while(cur)ѭ���ͽ���ȥ
//////���return newhead=NULL;
//////���ֻ��һ���ڵ㣬������ͷ��Ϳ���
////struct ListNode* reverseList(struct ListNode* head){
////	//��������ָ��newhead cur next;
////	//����newhead��������cur,next����������
////	//�ֱ�ָ��NULL,head,cur->next;
////	Node*newhead = NULL, *cur = head;
////	//��ֹ������curָ��NULL
////	//����ѭ������������cur!=NULL
////	//��while(cur)
////	while (cur)
////	{
////		//һ����curָ���Ԫ������������ȥ��
////		//cur��cur->next��ʧȥ��ϵ��
////		//������Ҫ����next=cur->next;
////		//���next=cur->nextӦ�÷���ѭ���������ͷ��֮ǰ
////		Node*next = cur->next;
////		//ͷ��
////		//���������cur->next=newhead
////		//��һ��curָ��NULL
////		//�Ժ�ÿ��cur�ŵ���������Ҫָ���ϴε����һ���ڵ�
////		cur->next = newhead;
////		//�����������cur��newhead;
////		newhead = cur;
////		//���������Ϊ��ʹcur��next����������
////		cur = next;
////	}
////	//��󷵻��������ͷ�ڵ�Ϳ�
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
////////����˼·��
////////�淽��
////////����
////////��ʼ��
////////NULL 1->2->NULL
////////n1  n2 n3
////////��һ��ѭ����
////////NULL<-1->2->NULL -��ת
////////     n1 n2  n3   -����   n3->nextҪ���ж�����if(n3)
////////�ڶ���ѭ����
////////NULL<-1<-2->NULL -��ת
////////        n1  n2   -����   whileѭ����������Ϊn2!=NULL
////////���return n1���з�ת�������ͷ�ڵ�
////////2->1->NULL
//////struct ListNode* reverseList(struct ListNode* head){
//////	//һ���������ж�����������������Ϊ�գ���������ֻ��һ���ڵ�
//////	//return head;���аɣ����÷�ת��
//////	if (head == NULL || head->next == NULL)
//////		return head;
//////	//��������ָ��n1,n2,n3
//////	//�ʼ�ֱ�ָ��NULL,head,head->next
//////	struct ListNode*n1 = NULL, *n2 = head, *n3 = head->next;
//////	//��n2!=NULL����Ҫ���� 
//////	//n2==NULL return n1���У���Ϊ��ʱ�����Ѿ���ת������
//////	while (n2)
//////	{
//////		n2->next = n1;
//////		n1 = n2;
//////		n2 = n3;
//////		//n3=n3->nextҪ���ж�����
//////		//��n3==NULL
//////		//n3��û�б�Ҫ�������������
//////		if (n3)
//////			n3 = n3->next;
//////	}
//////	//��ת�������ͷ�ڵ�Ϊn1;
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
//////����˼·��
//////�淽��
//////����
//////��ʼ��
//////NULL 1->2->NULL
//////n1  n2 n3
//////��һ��ѭ����
//////NULL<-1->2->NULL -��ת
//////     n1 n2  n3   -����   n3->nextҪ���ж�����if(n3)
//////�ڶ���ѭ����
//////NULL<-1<-2->NULL -��ת
//////        n1  n2   -����   whileѭ����������Ϊn2!=NULL
//////���return n1���з�ת�������ͷ�ڵ�
//////2->1->NULL
////struct ListNode* reverseList(struct ListNode* head){
////	//һ���������ж�����������������Ϊ�գ���������ֻ��һ���ڵ�
////	//return head;���аɣ����÷�ת��
////	if (head == NULL || head->next == NULL)
////		return head;
////	//��������ָ��n1,n2,n3
////	//�ʼ�ֱ�ָ��NULL,head,head->next
////	struct ListNode*n1 = NULL, *n2 = head, *n3 = head->next;
////	//��n2!=NULL����Ҫ���� 
////	//n2==NULL return n1���У���Ϊ��ʱ�����Ѿ���ת������
////	while (n2)
////	{
////		//-��ת
////		n2->next = n1;
////		//-����
////		n1 = n2;
////		n2 = n3;
////		//n3=n3->nextҪ���ж�����
////		//��n3==NULL
////		//n3��û�б�Ҫ�������������
////		if (n3)
////			n3 = n3->next;
////	}
////	//��ת�������ͷ�ڵ�Ϊn1;
////	return n1;
////}
////
////
//
//
//
////ͷ�巨
//typedef struct ListNode Node;
////����Ҫ���淽��-����һ��
////if(head==NULL||head->next==NULL)
////  return head;
////����ǿսڵ�
////cur=head=NULL;
////while(cur)ѭ���ͽ���ȥ
////���return newhead=NULL;
////���ֻ��һ���ڵ㣬������ͷ��Ϳ���
//struct ListNode* reverseList(struct ListNode* head){
//	//��������ָ��newhead cur next;
//	//����newhead��������cur,next����������
//	//�ֱ�ָ��NULL,head,cur->next;
//	Node*newhead = NULL, *cur = head;
//	//��ֹ������curָ��NULL
//	//����ѭ������������cur!=NULL
//	//��while(cur)
//	while (cur)
//	{
//		//һ����curָ���Ԫ������������ȥ��
//		//cur��cur->next��ʧȥ��ϵ��
//		//������Ҫ����next=cur->next;
//		//���next=cur->nextӦ�÷���ѭ���������ͷ��֮ǰ
//		Node*next = cur->next;
//		//ͷ��
//		//���������cur->next=newhead
//		//��һ��curָ��NULL
//		//�Ժ�ÿ��cur�ŵ���������Ҫָ���ϴε����һ���ڵ�
//		cur->next = newhead;
//		//�����������cur��newhead;
//		newhead = cur;
//		//���������Ϊ��ʹcur��next����������
//		cur = next;
//	}
//	//��󷵻��������ͷ�ڵ�Ϳ�
//	return newhead;
//}


//����˼·:
//ͷ�巨
//����һ��������
//����������Ľڵ�������ͷ��
//��һ��ѭ����
//������
//  1->2->NULL      -next=cur->next;
//cur next
//������
//newhead=NULL
//newhead=NULL<-1=cur   -cur->next=newhead;
//NULL<-1=newhead       -newhead=cur;
//������
//1->2>NULL
// cur/next      -cur=next;
//�ڶ���ѭ����
//������
//1->2->NULL
//   cur next     -next=cur->next
//������
//NULL<-1=newhead<-2=cur   -cur->next=newhead
//NULL<-1<-2=newahead   -newhead=cur;
//������:
//1->2->NULL
//     cur/next  -cur=next;
//��ʱcur==NULL,������������ѭ��
//���������ͷ���Ѿ�ȫ����ɣ�return newhead����

//ʹ��ͷ�巨��ɷ�ת����
//��ͬ����head==NULL����head->next==NULL
//���head==NULL����cur=NULL,�������whileѭ����ֱ��return newhead=NULL;
//���head->next==NULL ����whileѭ�� ͷ��һ���ڵ�� return newhead����
struct ListNode* reverseList(struct ListNode* head){
	//����һ���������ͷ�ڵ�newhead
	//�ʼ��newhead=NULL
	//����һ��cur,�ʼ����ָ��head
	struct ListNode*newhead = NULL, *cur = head;
	//ѭ������������cur!=NULL
	//��cur==NULL��ͷ���Ѿ�ȫ����ɣ�return newhead;
	while (cur)
	{
		//��Ҫ�ڶ���һ��next=cur->next;
		//����cur�õ�������ȥͷ���ʱ��cur��cur->next�ͻ�ʧȥ��ϵ
		//������
		struct ListNode*next = cur->next;
		//������
		cur->next = newhead;
		newhead = cur;
		//������
		cur = next;
	}
	//�����������ͷ�ڵ�
	return newhead;
}


typedef struct ListNode Node;
struct ListNode* removeElements(struct ListNode* head, int val){
	//˫ָ��
	//��������ָ��prev cur
	//���ʼ���������prev=NULL,cur=head;
	Node*prev = NULL, *cur = head;
	//���������ʱprevָ�����һ��Ԫ�أ�curָ��NULL
	//����ѭ����������Ϊcur
	while (cur)
	{
		//���cur->val==val
		//��Ҫɾ�������Ԫ��
		//prev cur
		// 1    6    2   3
		//prev->next=cur->next
		//ɾ�����Ԫ��
		//free(cur);
		//Ȼ���ٰ�cur=prev->next;
		if (cur->val == val)
		{
			//�����һ���ڵ����val�أ�
			//��ʱprev=NULL;
			//û������prev->next=cur->next;free(cur);cur=prev->next;����߼�ȥɾ������ڵ�
			//����
			//if�������ȿ�����cur==headҲ������prev==NULL
			//��ʱ
			//���¶���ͷ�ڵ㣺head=cur->next
			//Ȼ��ɾ�������Ԫ�أ� free(cur);
			//�ٰ�head����cur:cur=head;
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
				cur = prev->next;//��������һ��
				//������һ������val������Ҫ�ߵ�prevָ�����һ����ʱ�������
				//���ʱ��while��ѭ���ж��������cur��һ��Ұָ��
				//����Ҫ��cur��ΪNULL,��cur=prev->next
				//ɾ����val��,prev->nextΪNULL
			}


		}
		//���cur->val!=val��Ҫ����ָ��һ�������
		//��cur��prev,Ȼ��cur������
		//prev=cur;
		//cur=cur->next;
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	//��ĿҪ�󷵻��µ�ͷ�ڵ�-return head;
	return head;
}


//����˼·
//������������к�val��ͬ�Ľڵ��free��
//Ȼ�󷵻�ɾ���������ͷ�ڵ�
//˫ָ��
//���ֻ��һ��ָ��cur
//cur->val==val
//free(cur)֮��cur��cur->next��ʧȥ����ϵ

struct ListNode* deleteNode(struct ListNode* head, int val){
	//����prev��cur����ָ��
	//�ʼ*prev=NULL��*cur=head;
	struct ListNode*prev = NULL, *cur = head;
	//��cur==NULLѭ������
	while (cur)
	{
		//cur->val==val:ɾ�ڵ�
		if (cur->val == val)
		{
			//���head==val,��Ҫ���¶���ͷ�ڵ�
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
		//����ָ�����������
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	//����ɾ��֮�������ͷ�ڵ�
	return head;
}