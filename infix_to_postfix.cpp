#include<iostream>
#include<stack>

using namespace std;

string op;
stack<char> st;

bool isOp(char c) {
  return (c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' || c=='^');
}

int prec(char c) {
  switch(c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return -1;
  }
}

void infixToPostfix(const string &exp) {
  for(auto s : exp) {
    if(!isOp(s)) op+=s;
    else if(s == '(') st.push(s);
    else if(s == ')') {
      while(!st.empty() && st.top() != '(') {
        char c = st.top();
        st.pop();
        op+=c;
      }
      if(!st.empty() && st.top() == '(') {
        st.pop();
      } else if (st.empty()) {
        cout<<"Invalid Expr!!"<<endl;
        exit(1);
      }
    } else {
      while(!st.empty() && prec(s)<=prec(st.top())) {
        char c = st.top();
        st.pop();
        op+=c;
      }
      st.push(s);
    }
  }
  while(!st.empty()) {
    char c = st.top();
    st.pop();
    op+=c;
  }
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    cout<<op<<endl;
    return 0;
}
