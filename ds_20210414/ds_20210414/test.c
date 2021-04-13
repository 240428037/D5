#define _CRT_SECURE_NO_WARNINGS 1
//��������������
//���val��xС���Ͷ�less����β��
//���val��x�󣬾Ͷ�greater����β��
//����less�����β����greater�����ͷ���ٷ���less�����ͷ�ڵ�Ϳ�
typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x){
	//����less�����ͷ�ڵ��β�ڵ�
	ListNode*lesshead, *lesstail;
	//����greater�����ͷ�ڵ��Ϊ�ڵ�
	ListNode*greaterhead, *greatertail;
	//�ֱ�Ϊless��greater����̬���ٿռ�
	lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
	greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
	//�����������ͷ�ڵ�ָ��NULL
	lesshead->next = greaterhead->next = NULL;
	//����һ��curָ���ʼָ��head,Ȼ��������������������Ƚ�
	ListNode*cur = head;
	//��curָ��NULL,Ҳ�����ߵ���������ľ�ͷ����ʱѭ����ֹ
	while (cur)
	{
		//���cur->val<x
		//��curβ�嵽less����
		if (cur->val < x)
		{
			lesstail->next = cur;
			lesstail = lesstail->next;
		}
		//���cur->val>=x
		//��curβ�嵽greater����
		else
		{
			greatertail->next = cur;
			greatertail = greatertail->next;
		}
		//cur����������
		cur = cur->next;
	}
	//��less�����β����greater�����ͷ
	lesstail->next = greaterhead->next;
	//��greater�����βָ��NULL
	//��ֹ����ɻ�
	greatertail->next = NULL;
	//����һ��listָ��ָ��less�����ͷ�ڵ�
	ListNode*list = lesshead->next;
	//free��less��greater�����ͷ�ڵ�
	free(lesshead);
	free(greaterhead);
	//���return������
	return list;
}



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



