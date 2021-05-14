class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = 0; i < n; i++){
			nums1[m + i] = nums2[i];
		}
		sort(nums1.begin(), nums1.end());
	}
};


class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int>nums3(m + n);
		int i1 = 0, i2 = 0, i3 = 0;
		while (i1 < m&&i2 < n){
			if (nums1[i1] < nums2[i2]){
				nums3[i3] = nums1[i1];
				i3++;
				i1++;
			}
			else{
				nums3[i3] = nums2[i2];
				i3++;
				i2++;
			}
		}
		while (i1 < m){
			nums3[i3] = nums1[i1];
			i3++;
			i1++;
		}
		while (i2 < n){
			nums3[i3] = nums2[i2];
			i3++;
			i2++;
		}
		for (int i = 0; i < m + n; i++){
			nums1[i] = nums3[i];
		}
	}
};


class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i1 = m - 1, i2 = n - 1, tail = m + n - 1;
		int cur;
		while (i1 >= 0 || i2 >= 0){
			if (i1 == -1){
				cur = nums2[i2--];
			}
			else if (i2 == -1){
				cur = nums1[i1--];
			}
			else if (nums1[i1] > nums2[i2]){
				cur = nums1[i1--];//尾插-取大的尾插-不同于之前双指针逻辑
			}
			else{
				cur = nums2[i2--];
			}
			nums1[tail--] = cur;
		}
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
};