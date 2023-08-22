#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int maxPrime(string str){
    int prm = -1;
    for (int i = 0; i < str.size(); i++) {
        int num = str[i] - '0';
        if (isPrime(num) && num > prm) {
            prm = num;
        }
    }
    return prm;

}

int main(){
    int test;
    int digit;
    string str;
    for(int i=0; i<test; i++){
        cin>>str;
        int prime = maxPrime(str); 
        cout<<"Case "<<i+1<<": "<<(prime?prime:"This is a junk!")<<"\n";
    }
    return 0;
}