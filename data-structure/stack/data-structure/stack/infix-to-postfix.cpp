/* C++ implementation to convert infix expression to postfix*/

#include<iostream>
#include<stack>

using namespace std;

int precedence(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string output="";
    for (char x: s)
    {
        //for operand, just output it
        if ((x >= '0' && x <='9') || (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
        {
            output += x;
        }
        else if (x == '(')
        {
            st.push(x);
        }
        else if (x == ')')
        {
            while (st.top() != '(')
            {
                output += st.top();
                st.pop();
            }
            st.pop();
        }
        else // for operator
        {
            while (!st.empty() && precedence(x) <= precedence(st.top()))
            {
                output += st.top();
                st.pop();
            }
            st.push(x);
        }
    }
    while (!st.empty())
    {
        output += st.top();
        st.pop();
    }
    return output;
}

int main() {
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	cout << infixToPostfix(exp);    // Output: abcd^e-fgh*+^*+i-
	return 0;
}
