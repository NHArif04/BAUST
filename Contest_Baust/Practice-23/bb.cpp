#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    int aLen = a.size()-1;
    int bLen = b.size()-1;
    cout<<(((a[aLen]+b[bLen])%2)?"White":"Black")<<"\n";
    return 0;
}