class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int val = 0;
		for (auto e : nums){
			val ^= e;
		}
		return val;
	}
};


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int Array[32] = { 0 };
		for (auto val : nums){
			for (size_t i = 0; i < 32; i++){
				if (val&(1 << i)){
					Array[i]++;
				}
			}
		}
		int num = 0;
		for (size_t i = 0; i < 32; i++){
			if (Array[i] % 3 == 1){
				num |= (1 << i);
			}
		}
		return num;
	}
};




class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int arr[32] = { 0 };
		for (auto e : nums){
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
	vector<int> singleNumber(vector<int>& nums) {
		int val = 0;
		for (auto e : nums){
			val ^= e;
		}
		int i = 0;
		for (; i < 32; i++){
			if (val&(1 << i)){
				break;
			}
		}
		int num1 = 0, num2 = 0;
		for (auto e : nums){
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
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>vv;
		vv.resize(numRows);
		for (int i = 0; i < numRows; i++){
			vv[i].resize(i + 1);
			vv[i][0] = 1;
			vv[i][vv[i].size() - 1] = 1;
		}
		for (int i = 0; i < vv.size(); i++){
			for (int j = 0; j < vv[i].size(); j++){
				if (vv[i][j] != 1){
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
				}
			}
		}
		return vv;
	}
};