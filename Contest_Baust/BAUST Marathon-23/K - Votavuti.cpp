#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
    double candidate, elector;
    cin>>candidate>>elector;
    vector<int> votes(candidate+1,0);
    int voteControl = int(elector);
    while(voteControl--){
        int vote;
        cin>>vote;
        votes[vote]++;
    }
    for(int i=1; i<=candidate; i++){
        double result = (votes[i]/elector)*100;
        cout<<fixed<<setprecision(2)<<result<<"%"<<endl;
    }
    return 0;
}