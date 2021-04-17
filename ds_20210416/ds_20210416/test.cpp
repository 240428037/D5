#define _CRT_SECURE_NO_WARNINGS 1

//双指针-快慢指针
typedef struct ListNode Node;
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
	//定义两个指针slow fast
	//让fast先走k步
	//然后slow和fast再一起走
	//当fast指向NULL
	//slow就指向倒数第k个节点
	Node*slow = head, *fast = head;
	//让fast先走k步
	//需要加一个判断条件
	//如果k大于链表长度，那么return NULL;
	while (k--)
	{
		if (fast)
			fast = fast->next;
		else
			return NULL;
	}
	//fast走了k步以后
	//slow和fast再一起走
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	//最后return slow;
	return slow;
}