#include<iostream>
#include<stack>
//#include<algorithm>
//#include<cstdbool>

using namespace std;

stack<char>st;

int preced(char op){
    return (op == '+' || op=='-')?1:((op=='*' || op=='/')?2:0);
}

string postfixNotation(string exp){
    string finalExp="";
    for(auto ch:exp){
        if(isdigit(ch) || isalpha(ch)){
            finalExp+=ch;
        }else{
            while(!st.empty() && preced(st.top())>=preced(ch)){
                finalExp+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        finalExp+=st.top();
        st.pop();
    }
    return finalExp;
}



int main(){
    string infix="a*(b-c)";
    cout<<postfixNotation(infix);       //abc-*
    return 0;
}