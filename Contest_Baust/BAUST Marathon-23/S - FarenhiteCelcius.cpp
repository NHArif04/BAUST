#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int test;
    cin>>test;
    double celcius, fahrenheit, result;
    for(int i=1; i<=test; i++){
        cin>>celcius>>fahrenheit;
        result = ((9.0/5)*celcius + 32 + fahrenheit);
        result = 5.0/9*(result - 32);
        cout<<"Case "<<i<<": "<<fixed<<setprecision(2)<<result<<endl;
    }
    return 0;
}