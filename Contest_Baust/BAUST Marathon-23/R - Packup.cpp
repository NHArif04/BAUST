#include<iostream>
using namespace std;

int main(){
    int test;
    cin>>test;
    double length, width, height;
    for(int i=1; i<=test; i++){
        cin>>length>>width>>height;
        string result=(height<=20 && width<=20 && length<=20)?"good":"bad";
        cout<<"Case "<<i<<": "<<result<<endl;
    }
    return 0;
}