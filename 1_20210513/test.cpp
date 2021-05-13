





class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int n = nums.size();
		int left = 0;
		for (int right = 0; right < n; right++) {
			if (nums[right] != val) {
				nums[left] = nums[right];
				left++;
			}
		}
		return left;
	}
};

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0){
			return 0;
		}
		if (nums.empty()){
			return 0;
		}
		int dest = 0;
		for (int src = 0; src < nums.size(); src++){
			if (nums[src] != val){
				nums[dest] = nums[src];
				src++;
				dest++;
			}
		}
		return dest;
	}
};



class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()){
			return 0;
		}
		int dest = 0, src = 0;
		while (src < nums.size()){
			if (nums[src] != val){
				nums[dest] = nums[src];
				dest++;
				src++;
			}
			else{
				src++;
			}
		}
		return dest;
	}
};



class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()){
			return 0;
		}
		int dest = 0;
		for (int src = 0; src < nums.size(); src++){
			if (nums[src] != val){
				nums[dest] = nums[src];
				dest++;
			}
		}
		return dest;
	}
};


class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int left = 0, right = nums.size();//?
		while (left < right){
			if (nums[left] == val){
				nums[left] = nums[right - 1];//?
				right--;
			}
			else{
				left++;
			}
		}
		return left;//?
	}
};





class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()){
			return 0;
		}
		int dest = 0, prev = 0, cur = 1;
		while (cur < nums.size()){
			if (nums[prev] != nums[cur]){
				nums[dest] = nums[prev];
				dest++;
				prev++;
				cur++;
			}
			else{
				prev++;
				cur++;
			}
		}
		nums[dest] = nums[prev];
		dest++;
		return dest;
	}
};