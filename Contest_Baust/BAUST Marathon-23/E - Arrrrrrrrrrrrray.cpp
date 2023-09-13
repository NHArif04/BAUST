#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void traverse(vector<int> arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i];
        if(i<size-1)cout<<" ";
    }
    cout<<endl;
}

int main(){
    int test, size, opNumber, digit, sw1, sw2;
    cin>>test;
    char operation;
    for(int j=1; j<=test; j++){
        cin>>size>>opNumber;
        vector<int> arr(size,0);
        for(int i=0; i<size; i++){
            cin>>arr[i];
        }
        while(opNumber--){
            cin>>operation;
            switch (operation){
            case 'S':
                cin>>digit;
                for(int i=0; i<size; i++){
                    arr[i]+=digit;
                }
                break;
            
            case 'M':
                cin>>digit;
                for(int i=0; i<size; i++){
                    arr[i]*=digit;
                }
                break;

            case 'D':
                cin>>digit;
                for(int i=0; i<size; i++){
                    arr[i]/=digit;
                }
                break;
            
            case 'P':
                cin>>sw1>>sw2;
                arr[sw1]^=arr[sw2]^=arr[sw1]^=arr[sw2];
                break;
            
            case 'R':
                reverse(arr.begin(),arr.end());
                break;
            }
        }
        cout<<"Case "<<j<<": "<<endl;
        traverse(arr, size);
    }
    return 0;
}