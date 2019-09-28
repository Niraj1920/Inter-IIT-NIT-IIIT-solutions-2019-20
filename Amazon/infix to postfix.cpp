#include <iostream>
#include <stack>
using namespace std;

int prec(char ch){
    if(ch == '^')   return 3;
    if(ch == '*' || ch == '/')  return 2;
    if(ch == '+' || ch == '-')  return 1;
    return -1;
}
string infixtopostfix(string infix){
    string postfix = "";
    std::stack<char> s;
    
    for(int i=0; i<infix.length(); i++){
        if(infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z'){
            postfix += infix[i];
        }
        else if(infix[i] == '(')
            s.push(infix[i]);
        else if(infix[i] == ')'){
            while(!s.empty() && s.top() != '('){
                char ch = s.top();
                s.pop();
                postfix += ch;
            }
            if(s.top() == '(')
                s.pop();
        }
        else{
            while(!s.empty() && prec(infix[i]) <= prec(s.top())){
                char ch = s.top();
                s.pop();
                postfix += ch;
            }
            s.push(infix[i]);
        }
    }
    while(!s.empty()){
        char ch = s.top();
        s.pop();
        postfix += ch;
    }
    return postfix;
}
int main()
{
    string infix = "a+b-c*d";
    
    cout<<infixtopostfix(infix)<<endl;
    return 0;
}
