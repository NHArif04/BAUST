#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack <char> st;
    st.push('$');
    string exp = "{}}{(sd)(sdf)f(g)sdfg(sdf)a{g}{b{}v}c";

    for(int i=0; exp[i]!='\0'; i++){
        if((st.top()=='(' && exp[i]!=')') || (st.top() == '{' && exp[i]!='}') || (st.top() == '[' && exp[i]!=']') || (st.top()=='$' && (exp[i]=='(' || exp[i]=='{' || exp[i]=='[' || exp[i]==')' || exp[i]=='}' || exp[i]==']'))){
            if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[' || exp[i]==')' || exp[i]=='}' || exp[i]==']'){
                cout << "push-> " << exp[i]<<endl; 
                st.push(exp[i]);
            }
        }else if((st.top()=='(' && exp[i]==')') || (st.top() == '{' && exp[i]=='}') || (st.top() == '[' && exp[i]==']')){
            cout << "pop-> " << st.top()<<exp[i]<<endl; 
            st.pop();
        }
    }

    st.top()=='$'?cout<<"Balanced":cout<<st.top()<<" Imbalanced";
    return 0;
}