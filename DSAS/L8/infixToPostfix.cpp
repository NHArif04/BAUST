#include<iostream>
#include<stack>
//#include<algorithm>
//#include<cstdbool>

using namespace std;

stack<char>st;

int prec(char op){
    return (op == '+' || op=='-')?1:((op=='*' || op=='/')?2:0);
}

string postfixNotation(string exp){
    string finalExp="";
    for(auto ch:exp){
        if(isdigit(ch) || isalpha(ch)){
            finalExp+=ch;
        }else{
            while(!st.empty() && prec(st.top())>=prec(ch)){
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

string subExp(string exp){
    int i = 0, j = exp.size();
    string result="", substr="";
    while(exp[i]!='(' || exp[j]!=')'){
        if(exp[i]!='('){
            i++;
        }
        if(exp[j]!=')'){
            j--;
        }
    }
    cout<<i<<" "<<j<<endl;
    
    int temp = i+1;
    while(temp<j){
        cout<<temp<<" "<<j<<endl;
        substr+=exp[temp];
        temp++;
    }
    cout<<"Sub str: "<<substr<<endl;
    
    result=postfixNotation(substr);
    return result;
}

int main(){
    string infix="a*(b-c)";
    cout<<subExp(infix);
    return 0;
}