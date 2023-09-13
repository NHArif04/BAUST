#include<iostream>
using namespace std;

int main(){
    int test, opNumber, donate, total;
    cin>>test;
    string operation;
    for(int i=1; i<=test; i++){
        cin>>opNumber;
        total = 0;
        cout<<"Case "<<i<<": "<<endl;
        while(opNumber--){
            cin>>operation;
            if(operation == "donate"){
                cin>>donate;
                total+=donate;
            }
            if(operation == "report"){
                cout<<total<<endl;
            }
        }
    }
    return 0;
}