#include<iostream>
using namespace std;

int main(){
    int test, players, start, passes;
    cin>>test;
    for(int i=1; i<=test; i++){
        cin >>players >>start >>passes ;
        int player = (start+passes-1)%(players)+1;
        cout<<"Case "<<i<<": "<<player<<endl;
    }
    return 0;
}