#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string postfix){
    stack<int> s;
    for(int i=0; i<postfix.length(); i++){
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            s.push(postfix[i] - 48);
        }
        else{
            int a, b, res = 0;
            if(!s.empty()){
                a = s.top();
                s.pop();
            }
            else    return -1;
            if(!s.empty()){
                b = s.top();
                s.pop();
            }
            else    return -1;
            switch(postfix[i]){
                case '+':   res = a + b;break;
                case '-':   res = a - b;break;
                case '*':   res = a * b;break;
                case '/':   res = a / b;break;
                case '^':   res = a ^ b;break;
            }
            s.push(res);
            cout<<a<<" "<<postfix[i]<<" "<<b<<" "<<res<<endl;
        }
    }
    return s.top();
}
int main()
{
    string postfix = "56+5*";
    
    cout<<evaluatePostfix(postfix)<<endl;
    return 0;
}
