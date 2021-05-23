//#include<iostream>
//#include<string>
//using namespace std;
//int main(){
////	string str, cur, ret;
////	cin >> str;
////	for (int i = 0; i <= str.size(); i++){
////		if (str[i] >= '0'&&str[i] <= '9'){
////			cur += str[i];
////		}
////		else{
////			if (cur.size() > ret.size()){
////				ret = cur;
////			}
////			else{
////				cur.clear();
////			}
////		}
////	}
////	cout << ret << endl;
//	string s = "123";
//	cout << s[0] << endl;
//	return 0;
//}




#include<iostream>
#include<string>
using namespace std;
int main(){
	string s, cur, ret;
	cin >> s;
	//for循环的控制条件本来应该是i<s.size()
	//但是如果这个字符串的连续最长数字串在字符串末尾
	//最后一次if判断+=到cur上 下一次循环进不来 没法ret=cur；
	for (int i = 0; i <= s.size(); i++){
		//注意>=<=不要遗漏=
		if (s[i] >= '0'&&s[i] <= '9'){
			cur += s[i];
		}
		else{
			if (cur.size() > ret.size()){
				ret = cur;
			}
			else{
				cur.clear();
			}
		}
	}
	cout << ret << endl;
	return 0;
}


class Solution {
public:
	int majorityElement(vector<int>& nums) {
		if (nums.empty()){
			return 0;
		}
		sort(nums.begin(), nums.end());
		int mid = nums.size() / 2;
		int count = 0;
		for (int i = 0; i<nums.size(); i++){
			if (nums[i] == nums[mid]){
				count++;
			}
		}
		return count>nums.size() / 2 ? nums[mid] : 0;
	}
};



class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int result = nums[0];
		int times = 1;
		for (int i = 1; i < nums.size(); i++){
			if (times == 0){
				result = nums[i];
				times = 1;
			}
			else{
				if (nums[i] == result){
					times++;
				}
				else{
					times--;
				}
			}
		}
		int count = 0;
		for (int i = 0; i<nums.size(); i++){
			if (result == nums[i]){
				count++;
			}
		}
		return count>nums.size() / 2 ? result : 0;
	}
};



class Solution {
public:
	int majorityElement(vector<int>& nums) {
		if (nums.empty()){
			return 0;
		}
		sort(nums.begin(), nums.end());
		int mid = nums.size() / 2;
		int count = 0;
		for (int i = 0; i<nums.size(); i++){
			if (nums[i] == nums[mid]){
				count++;
			}
		}
		return count>nums.size() / 2 ? nums[mid] : 0;
	}
};