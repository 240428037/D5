class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode*prev = nullptr, *cur = head;
		while (cur){
			if (cur->val == val){
				if (cur == head){
					head = cur->next;
					delete(cur);
					cur = head;
				}
				else{
					prev->next = cur->next;
					delete(cur);
					cur = prev->next;
				}
			}
			else{
				prev = cur;
				cur = cur->next;
			}
		}
		return head;
	}
};



class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode*prev = NULL, *cur = pHead, *next = cur->next;
		while (next)
		{
			if (cur->val != next->val)
			{
				prev = cur;
				cur = next;
				next = next->next;
			}
			else
			{
				//next
				//-12333
				while (next&&cur->val == next->val)
					next = next->next;
				//prev
				//-11123
				if (prev)
					prev->next = next;
				else
					pHead = next;
				//cur
				while (cur != next)
				{
					ListNode*del = cur;
					cur = cur->next;
					free(del);
				}
				//next
				//-12333
				if (next)
					next = cur->next;
			}
		}
		return pHead;
	}
};




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
		if (l1->val < l2->val){
			head = tail = l1;
			l1 = l1->next;
		}
		else{
			head = tail = l2;
			l2 = l2->next;
		}
		while (l1&&l2){
			if (l1->val < l2->val){
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