#include<iostream>
#include<array>
using namespace std;
void traverseArray(int arr[], int len);

int main(){
    int array[] = {1,2,3,4,5};
    int length = sizeof(array)/sizeof(array[0]);
    cout<<"Length of  the array is: "<<length<<endl;

    int index = 2;
    cout<<index<<" of the element is: "<<array[index]<<endl<<endl;
    traverseArray(array, length);
    return 0;
}

void traverseArray(int arr[], int len){
    cout<<"Array is: ";
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"Success!";
}