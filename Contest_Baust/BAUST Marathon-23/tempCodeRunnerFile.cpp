#include<iostream>
using namespace std;

int main(){
    unsigned test,n;
    cin>>test;
    while(test--){
        cin >> n;
        int a,b,c;
        a = b = c = n/3;
        c+=(n%3);
        for(int i=1;; i++){
            if(a%3==0){
                a-=i;
                b+=i;
            }
            if(b%3==0){
                b-=i;
                c+=i;
            }
            if(c%3==0){
                c-=i;
                a+=i;
                
            }else{
                break;
            }
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}