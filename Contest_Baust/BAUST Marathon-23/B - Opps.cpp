#include<iostream>
#include<vector>
using namespace std;

int main(){
    unsigned test,i;
    // vector<unsigned> freq(21,-1);
    cin>>test;
    while(test--){
        cin >> i;
        /* freq[i]++;
        int a = i>10?i-10-freq[i]:freq[i]>0?freq[i]:0;
        int b = i>10?i-a:i-freq[i]; */
        if(i>20) break;
        int a,b;
        i>10? (a = i-10, b = 10) : (a=0, b=i);
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}