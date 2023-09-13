#include<iostream>
using namespace std;

int main(){
    int test, walls;
    cin>>test;
    for(int i=1; i<=test; i++){
        cin >>walls;
        int height[walls];
        int low=0, high = 0;
        for(int i=0; i<walls; i++){
            cin>>height[i];
            if(i>=1 && height[i] > height[i-1]){
                high++;
            }else if(i>=1 && height[i] < height[i-1]){
                low++;
            }
        }
        cout<<"Case "<<i<<": "<<high<<" "<<low<<endl;
    }
    return 0;
}