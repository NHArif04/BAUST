#include<iostream>
using namespace std;
int searchArray(int arr[], int len, int target);

int main(){
    int array[] = {1,2,3,4,5,6};
    int length;
    length = array.size();
    cout<<"Length is: "<<length<<endl;
    int target = 7;
    int index = 0;
    cout<<target<<(searchArray(array, length, target, index)?" Found":" Not found");
    return 0;
}

int searchArray(int arr[], int len, int target, int index){
    for(int i=0; i<len; i++){
        if(target == arr[i])
            index = 0;
            return true;
    }
    return false;
}
