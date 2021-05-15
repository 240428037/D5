class MinStack {
public:
	MinStack() {

	}
	void push(int val) {
		st.push(val);
		if (minst.empty() || val <= minst.top()){
			minst.push(val);
		}
	}
	void pop() {
		if (minst.top() == st.top()){
			minst.pop();
		}
		st.pop();
	}
	int top() {
		return st.top();
	}
	int getMin() {
		return minst.top();
	}
	stack<int> st;
	stack<int> minst;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(val);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/




class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int>st;
		int pushi = 0, popi = 0;
		while (pushi < pushV.size()){
			st.push(pushV[pushi]);
			pushi++;
			while (!st.empty() && st.top() == popV[popi]){
				st.pop();
				popi++;
			}
		}
		return st.empty();
	}
};


class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (auto&str : tokens){
			if (str == "+" || str == "-" || str == "*" || str == "/"){
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				switch (str[0]){
				case'+':
					st.push(left + right);
					break;
				case'-':
					st.push(left - right);
					break;
				case'*':
					st.push(left*right);
					break;
				case'/':
					st.push(left / right);
					break;
				}
			}
			else{
				st.push(stoi(str));
			}
		}
		return st.top();
	}
};


class Solution {
public:
	int StrToInt(string str) {
		if (str.empty()){
			return 0;
		}
		int flag = 1;
		if (str[0] == '+'){
			flag = 1;
			str[0] = '0';
		}
		if (str[0] == '-'){
			flag = -1;
			str[0] = '0';
		}
		int sum = 0;
		for (int i = 0; i < str.size(); i++){
			if (str[i]<'0' || str[i]>'9'){
				sum = 0;
				break;
			}
			sum = sum * 10 + (str[i] - '0');
		}
		return flag*sum;
	}
};