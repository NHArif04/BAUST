#include<iostream>
//#include<stack>
#include<string>
#include<cstdbool>
#include<algorithm>

using namespace std;
#define Size 40

//stack implementation
template <class T> class Stack{
    private:
        int t;
        T st[Size];

    public:
        Stack();
        void push(T);
        T pop();
        T top();
        bool isFull();
        bool isEmpty();
};

template<class T> Stack <T> :: Stack(){t=-1;}
template<class T> void Stack <T> :: push(T k){
    if(isFull()){
        cout<<"Stack is full"<<endl;
        return;
    }
    cout<<"Inserted Element "<< k <<endl;
    t++;
    st[t]=k;
}
template<class T> bool Stack <T> :: isEmpty(){return (t==-1)? true:false;}
template<class T> bool Stack <T> :: isFull(){return (Size-1)? true:false;}
template<class T>  T Stack <T> :: pop() {t--;return st[t+1];}
template<class T> T Stack <T> :: top(){return st[t];}


//reverse function




int getResult(int op1, int op2, int opnd){
    int result;
    switch (opnd) {
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1 - op2;
            break;
        case '*':
            result = op1 * op2;
            break;
        case '/':
            result = op1 / op2;
            break;
        default:
            break;
    }
    return result;
}

void postfix(){
    string exp="23*54*+9-";
    Stack<char> st;
    bool flag = true;
    int op1, op2;
    for(auto ch : exp){
        if(ch-'0'>=0 && ch-'0'<=9){
            st.push(ch);
        }else{
            op2 = st.top()-'0';
            st.pop();
            op1 = st.top()-'0';
            st.pop();
            st.push('0'+getResult(op1,op2,ch));
        }
    }

    cout<<"Result of postfix notation: "<<st.top()-'0'<<endl<<endl;
    st.pop();
}

void prefix(){
    string exp="-+*23*549";
    reverse(exp.begin(), exp.end());
    stack<char> st;
    bool flag = true;
    int op1, op2;
    for(auto ch : exp){
        if(ch-'0'>=0 && ch-'0'<=9){     //isDigit(ch)
            st.push(ch);
        }else{
            op1 = st.top()-'0';
            st.pop();
            op2 = st.top()-'0';
            st.pop();
            st.push('0'+getResult(op1,op2,ch));
        }
    }

    cout<<"Result of prefix notation: "<<st.top()-'0'<<endl<<endl;
    st.pop();
}

int main(){
    int option;
    while(true){
        cout<<"Notation:"<<endl<<"1. Postfix\n2. Prefix"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            postfix();
            break;

        case 2:
            prefix();
            break;

        default:
            cout<<"Invalid Choice, try again"<<endl;
            getchar();
            system("cls");
            break;
        }
    }
    return 0;
}