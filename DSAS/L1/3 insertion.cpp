#include<iostream>
#include<array>
using namespace std;

void traverseArray(int arr[], int len);
void insertionArray(int arr[],int newLen, int newVal);
void insertionArray(int arr[], int newVal, int targetIndex, int &newLength, int length);

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
    int targetIndex = 2;
    newLength = length+1;

    insertionArray(array, newLength, newValue);

    insertionArray(array, newValue, targetIndex, newLength, length);

    cout<<"New Array is: ";
    traverseArray(array, newLength);
    return 0;
}

void insertionArray(int arr[], int newLen, int newVal){
    arr[newLen-1] = newVal;
}

void insertionArray(int arr[], int newVal, int targetIndex, int &newLength, int length){
    int temp;
    newLength ++;
    for(int i = targetIndex; i<newLength; i++){
        temp = arr[i];
        arr[i] = newVal;
        newVal = temp;
    }
}

void traverseArray(int arr[], int len){
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Success!"<<endl<<endl;
}
