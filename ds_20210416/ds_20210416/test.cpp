#define _CRT_SECURE_NO_WARNINGS 1

//˫ָ��-����ָ��
typedef struct ListNode Node;
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
	//��������ָ��slow fast
	//��fast����k��
	//Ȼ��slow��fast��һ����
	//��fastָ��NULL
	//slow��ָ������k���ڵ�
	Node*slow = head, *fast = head;
	//��fast����k��
	//��Ҫ��һ���ж�����
	//���k���������ȣ���ôreturn NULL;
	while (k--)
	{
		if (fast)
			fast = fast->next;
		else
			return NULL;
	}
	//fast����k���Ժ�
	//slow��fast��һ����
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	//���return slow;
	return slow;
}