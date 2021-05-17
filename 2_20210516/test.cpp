//#include <iostream>
//using namespace std;
//int main(){
//	cout << sizeof(char) << endl;//1
//	cout << sizeof(short) << endl;//2
//	cout << sizeof(int) << endl;//4
//	cout << sizeof(long) << endl;//4
//	cout << sizeof(long long) << endl;//8
//	cout << sizeof(float) << endl;//4
//	cout << sizeof(double) << endl;//8
//}


class Solution {
public:
	string replaceSpace(string s) {
		string str;
		for (auto&c : s){
			if (c == ' '){
				str += "%20";
			}
			else{
				str += c;
			}
		}
		return str;
	}
};



class CQueue {
	stack<int> stack1, stack2;
public:
	CQueue() {
		while (!stack1.empty()) {
			stack1.pop();
		}
		while (!stack2.empty()) {
			stack2.pop();
		}
	}

	void appendTail(int value) {
		stack1.push(value);
	}

	int deleteHead() {
		// 如果第二个栈为空
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.empty()) {
			return -1;
		}
		else {
			int deleteItem = stack2.top();
			stack2.pop();
			return deleteItem;
		}
	}
};



class CQueue {
public:
	stack<int>st1, st2;
	CQueue() {
		while (!st1.empty()){
			st1.pop();
		}
		while (!st2.empty()){
			st2.pop();
		}
	}

	void appendTail(int value) {
		st1.push(value);
	}

	int deleteHead() {
		if (st2.empty()){
			while (!st1.empty()){
				st2.push(st1.top());
				st1.pop();
			}
		}
		if (st2.empty()){
			return -1;
		}
		else{
			int tmp = st2.top();
			st2.pop();
			return tmp;
		}
	}
};



class CQueue {
public:
	stack<int>st1, st2;
	CQueue() {

	}

	void appendTail(int value) {
		st1.push(value);
	}

	int deleteHead() {
		if (st2.size() <= 0){
			while (st1.size()){
				st2.push(st1.top());
				st1.pop();
			}
		}
		if (st2.empty())
			return -1;
		int tmp = st2.top();
		st2.pop();
		return tmp;
	}
};