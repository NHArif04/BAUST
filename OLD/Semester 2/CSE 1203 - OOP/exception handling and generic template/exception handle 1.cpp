#include<iostream>
using namespace std;

int main()
{
    double a,b,ans;
    cout<<"Enter First Digit: ";
    cin>>a;
    cout<<"Enter Second Digit: ";
    cin>>b;
    if(b==0){
        try{
            if(b==0 or a==0){}
                throw 0;
        }
            else{
            ans=a/b;
            cout<<"answer 1 is :"<<ans;
            }
        }
        catch(int &ex){
            if(a==0){
                throw 0;
            }
            ans = static_cast<double> (a)/b;
            cout<<ex<<" => value of ex";
            cerr<<"answer 2 is : "<<ans;
        }
        catch(...){
            ans = static_cast<double> (a)/b;
            cerr<<"answer 3 is : "<<ans;
        }
    }
    return 0;
}