#include<iostream>
using namespace std;
int searchArray(int arr[], int len, int target, int &index);
void traverseArray(int arr[], int len);
void updateArray(int arr[], int len, int target, int &index);
int main(){
    int array[] = {1,2,3,4,5,6};
    int length;
    length = sizeof(array)/sizeof(array[0]);
    cout<<"Length is: "<<length<<endl;
    traverseArray(array, length);
    int target = 7;
    int index{};
    int updateValue = 6;
    updateArray(array, length, target, index);
    traverseArray(array, length);
    return 0;
}


int searchArray(int arr[], int len, int target, int &index){
    for(int i=0; i<len; i++){
        if(target == arr[i])
            index = i;
            return true;
    }
    return false;
}


void traverseArray(int arr[], int len){
    cout<<"Array is: ";
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"Success!"<<endl;
}



void updateArray(int arr[], int len, int target, int &index){
    if(searchArray(array, length, target, index)){
        cout<<target<<" Found\nUpdated Array is: ";    
        array[index] = updateValue;
    }
    else 
        cout<<target<<" Not found";
}