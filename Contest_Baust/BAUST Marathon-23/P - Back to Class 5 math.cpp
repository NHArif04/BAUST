#include<iostream>
using namespace std;

int main(){
    int test;
    cin>>test;
    unsigned long a, b, c, d;
    while(test--){
        cin>>a>>b>>c>>d;
        string result = (a==b && b==c && c==d)?("square"):((a==c && b == d || a==b && c==d || a==d && b==c)?("rectangle"):((a>=b+c+d || b>=a+c+d || c>=a+b+d || d>=a+b+c)?"banana":"quadrangle"));
        cout<<result<<endl;
    }
    return 0;
}