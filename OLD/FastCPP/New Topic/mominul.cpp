#include<iostream>
using namespace std;
int main(){
    int p[1];
    cout<<sizeof(p)<<endl;
    int i;
    while(1)
    {
        p[i]=i;
        cout<<p[i]<<endl;
        i++;
    }
    cout<<sizeof(p);
    return 0;
}