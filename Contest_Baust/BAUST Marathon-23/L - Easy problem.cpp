#include<iostream>
using namespace std;

int main(){
    unsigned n;
    cin >> n;
    int a,b,c;
    n%3==0 && n>3? (a = b = ((n/3)-1), c = ((n/3)+2)) : (n==3?a = b = c= (n/3) : a = b = c = n/3, c+=(n%3));
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
    return 0;
}