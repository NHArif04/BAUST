#include<iostream>
using namespace std;

int main(){
    int test, eggNumber, maxEgg, maxWeight;
    cin>>test;
    for(int i=1; i<=test; i++){
        cin>>eggNumber>>maxEgg>>maxWeight;
        int result = 0;
        for(int i=1; i<=eggNumber; i++){
            int weight;
            cin>>weight;
            if(i<=eggNumber && i<=maxEgg && maxWeight>=weight){
                maxWeight-=weight;
                result++;
            }
        }
        cout<<"Case "<<i<<": "<<result<<endl;
    }
    return 0;
}