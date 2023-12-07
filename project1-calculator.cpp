#include <iostream>
#include <stack>
#include <string>;
using namespace std;
int Priority(char c) {
	if (c == '_' || c == '+')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '^')
		return 3;
	else
		return 0;
}
string infix_to_postfix(string exp) {
	stack<char> stk;
	string output = "";
	//----------------
	for (int i = 0; i < exp.length();i++) {
		// Remove Spaces
		if (exp[i] == ' ') continue;
		// If Digit
		if (isdigit(exp[i]) || isalpha(exp[i]))
			output += exp[i];
		else if (exp[i] == '(')
			stk.push('(');
		else if (exp[i] == ')') {
			while (stk.top() != '(')
			{
				output += stk.top();
				stk.pop();
			}
			stk.pop(); // Remove the '('
		}
		else {
			while (!stk.empty() && Priority(exp[i]) <= Priority(stk.top())) {
				output += stk.top();
				stk.pop();
			}
			stk.push(exp[i]);
		}
	}
	while (!stk.empty()) {
		output += stk.top();
		stk.pop();
	}
	return output;
}
int main() {
	string infixExpression = ("(3+2)+7/2*((7 + 3)*2)");
	cout << infix_to_postfix(infixExpression) << endl;

	return 0;
}