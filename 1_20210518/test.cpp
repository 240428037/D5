/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr){
			return l2;
		}
		if (l2 == nullptr){
			return l1;
		}
		ListNode*head = nullptr, *tail = nullptr;
		if (l1->val<l2->val){
			head = tail = l1;
			l1 = l1->next;
		}
		else{
			head = tail = l2;
			l2 = l2->next;
		}
		while (l1&&l2){
			if (l1->val<l2->val){
				tail->next = l1;
				tail = tail->next;
				l1 = l1->next;
			}
			else{
				tail->next = l2;
				tail = tail->next;
				l2 = l2->next;
			}
		}
		while (l1){
			tail->next = l1;
			tail = tail->next;
			l1 = l1->next;
		}
		while (l2){
			tail->next = l2;
			tail = tail->next;
			l2 = l2->next;
		}
		return head;
	}
};





class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode*slow = head, *fast = head;
		while (k--){
			if (fast){
				fast = fast->next;
			}
			else{
				return nullptr;
			}
		}
		while (fast){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};




class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode*curA = headA, *curB = headB;
		int la = 0, lb = 0;
		while (curA){
			la++;
			curA = curA->next;
		}
		while (curB){
			lb++;
			curB = curB->next;
		}
		ListNode*longlist = headA, *shortlist = headB;
		if (la < lb){
			longlist = headB;
			shortlist = headA;
		}
		int gap = abs(la - lb);
		while (gap--){
			longlist = longlist->next;
		}
		while (longlist){
			if (longlist == shortlist){
				return longlist;
			}
			longlist = longlist->next;
			shortlist = shortlist->next;
		}
		return nullptr;
	}
};




class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr){
			return nullptr;
		}
		//1.拷贝原链表的每一个节点 链接到原节点
		//          copy
		//     2             1
		//head/cur          
		Node*cur = head;
		while (cur){
			Node*copy = new Node(cur->val);
			copy->next = cur->next;//1
			cur->next = copy;//2
			cur = copy->next;//迭代
		}
		//2.处理拷贝结点的random
		//      copy
		//cur
		cur = head;
		while (cur){
			Node*copy = cur->next;
			if (cur->random){
				copy->random = cur->random->next;
			}
			else{
				copy->random = nullptr;
			}
			cur = copy->next;//迭代
		}
		//3.拆分
		//         copy/copyhead
		//      1                2
		//head/cur                  next
		Node* copyhead = head->next;
		cur = head;
		while (cur){
			Node*copy = cur->next;//1
			Node*next = copy->next;//2
			cur->next = next;//断开
			if (next){
				copy->next = next->next;
			}
			else{
				copy->next = nullptr;
			}
			cur = next;//迭代
		}
		return copyhead;
	}
};



class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr){
			return nullptr;
		}
		//1.拷贝原链表的每一个节点 链接到原节点
		//          copy
		//     2             1
		//head/cur          
		Node*cur = head;
		while (cur){
			Node*copy = new Node(cur->val);
			copy->next = cur->next;//1
			cur->next = copy;//2
			cur = copy->next;//迭代
		}
		//2.处理拷贝结点的random
		//      copy
		//cur
		cur = head;
		while (cur){
			Node*copy = cur->next;
			if (cur->random){
				copy->random = cur->random->next;
			}
			else{
				copy->random = nullptr;
			}
			cur = copy->next;//迭代
		}
		//3.拆分
		//         copy/copyhead
		//      1                2
		//head/cur                  next
		Node* copyhead = head->next;
		cur = head;
		while (cur){
			Node*copy = cur->next;//1
			Node*next = copy->next;//2
			cur->next = next;//断开
			if (next){
				copy->next = next->next;
			}
			else{
				copy->next = nullptr;
			}
			cur = next;//迭代
		}
		return copyhead;
	}
};