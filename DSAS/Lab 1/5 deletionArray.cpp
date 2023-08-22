#include<iostream>
#include<array>
using namespace std;

void traverseArray(int arr[], int len);
void deletionArray(int arr[],int newLen, int newVal);
void deletionArray(int arr[], int newVal, int targetIndex, int &length);
int searchArray(int arr[], int len, int target, int index);

int main(){
    int array[10];
    array[0] =  1;
    array[1] =  3;
    array[2] =  2;
    array[3] =  4;

    int length = 4;
    cout<<"Array is: ";
    traverseArray(array,length);

    int newLength{};
    int newValue = 9;
    int target = 3;
    int targetIndex;
    
    searchArray(array, length, target, index);

    deletionArray(array, newLength, newValue);

    deletionArray(array, newValue, targetIndex, length);

    cout<<"New Array is: ";
    traverseArray(array, newLength);
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



void deletionArray(int arr[], int newVal, int targetIndex, int &length){
    length --;
    for(int i = targetIndex; i<length; i++){
        arr[i] = arr[i+1];
    }
}

void traverseArray(int arr[], int len){
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Success!"<<endl<<endl;
}
