class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (auto&e : nums){
			ret ^= e;
		}
		return ret;
	}
};



class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int val = 0;
		for (auto&e : nums){
			val ^= e;
		}
		int i = 0;
		for (; i < 32; i++){
			if (val&(1 << i)){
				break;
			}
		}
		int num1 = 0, num2 = 0;
		for (auto&e : nums){
			if (e&(1 << i)){
				num1 ^= e;
			}
			else{
				num2 ^= e;
			}
		}
		vector<int>v;
		v.push_back(num1);
		v.push_back(num2);
		return v;
	}
};


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int arr[32] = { 0 };
		for (auto&e : nums){
			for (int i = 0; i < 32; i++){
				if (e&(1 << i)){
					arr[i]++;
				}
			}
		}
		int num = 0;
		for (int i = 0; i < 32; i++){
			if (arr[i] % 3 == 1){
				num |= (1 << i);
			}
		}
		return num;
	}
};



class Solution {
public:
	void reverse(vector<int>&nums, int begin, int end){
		while (begin < end){
			swap(nums[begin], nums[end]);
			begin++;
			end--;
		}
	}
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		reverse(nums, 0, nums.size() - k - 1);
		reverse(nums, nums.size() - k, nums.size() - 1);
		reverse(nums, 0, nums.size() - 1);
	}
};s