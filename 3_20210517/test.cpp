class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		for (int i = 0; i < 32; i++){
			if (n&(1 << i)){
				count++;
			}
		}
		return count;
	}
};



class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n){
			if (n % 2 == 1){
				count++;
			}
			n /= 2;
		}
		return count;
	}
};



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
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr){
			return head;
		}
		ListNode*n1 = nullptr, *n2 = head, *n3 = head->next;
		while (n2){
			n2->next = n1;
			n1 = n2;
			n2 = n3;
			if (n3){
				n3 = n3->next;
			}
		}
		return n1;
	}
};




class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode*newahead = nullptr, *cur = head;
		while (cur){
			ListNode*next = cur->next;
			cur->next = newahead;
			newahead = cur;
			cur = next;
		}
		return newahead;
	}
};



class Solution {
public:
	void bubblesort1(vector<int>&nums){
		int n = nums.size();
		for (int i = 0; i < n - 1; i++){
			int flag = 0;
			for (int j = 0; j<n - 1 - i; j++){
				if (nums[j]>nums[j + 1]){
					swap(nums[j], nums[j + 1]);
					flag = 1;
				}
			}
			if (flag == 0)break;
		}
	}
	void bubblesort2(vector<int>&nums){
		int n = nums.size();
		for (int end = n - 1; end > 0; end--){
			int flag = 0;
			for (int i = 0; i<end; i++){
				if (nums[i]>nums[i + 1])
					flag = 1;
			}
			if (flag == 0)break;
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		bubblesort2(nums);
		return nums;
	}
};



/////////////////////////////////
void Swap(int*p1, int*p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//左右指针法-hoare
int PartSort(int*a, int begin, int end)
{
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
			begin++;
		while (begin < end&&a[end] >= key)
			end--;
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}
//挖坑法-DigPitMethod
int PartSort2(int*a, int begin, int end)
{
	int key = a[end];
	while (begin < end)
	{
		//找大
		while (begin < end&&a[begin] <= key)
			begin++;
		a[end] = a[begin];//找到大扔到右边的坑里去，同时begin形成新的坑
		while (begin < end&&a[end] >= key)
			end--;
		a[begin] = a[end];//找到小扔到左边的坑里去，同时end形成新的坑
	}
	a[begin] = key;
	return begin;
}


void QuickSort(int*a, int begin, int end)
{
	if (begin >= end)
		return;
	int keyindex = PartSort2(a, begin, end);
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);
}
int* sortArray(int* nums, int numsSize, int* returnSize){
	QuickSort(nums, 0, numsSize - 1);
	*returnSize = numsSize;
	return nums;
}



class Solution {
public:
	int partsort(vector<int>nums, int begin, int end){
		int key = nums[end];
		while (begin < end){
			while (begin < end&&nums[begin] <= key){
				begin++;
			}
			nums[end] = nums[begin];
			while (begin < end&&nums[end] >= key){
				end--;
			}
			nums[begin] = nums[end];
		}
		nums[begin] = key;
		return begin;
	}
	void quicksort(vector<int>&nums, int begin, int end){
		if (begin >= end){
			return;
		}
		int keyindex = partsort(nums, begin, end);
		quicksort(nums, begin, keyindex - 1);
		quicksort(nums, keyindex + 1, end);
	}
	vector<int> sortArray(vector<int>& nums) {
		int begin = 0;
		int end = nums.size() - 1;
		quicksort(nums, begin, end);
		return nums;
	}
};