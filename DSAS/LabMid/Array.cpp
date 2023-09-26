#include<iostream>
using namespace std;

void arrayTraverse(int arr[], int len);
int arraySearch(int arr[], int len, int target);
int arrayBinarySearch(int arr[], int len, int target);
void arrayInsertion(int arr[], int &len, int index, int value);
void arrayUpdate(int arr[], int len, int value, int newValue);
void arrayDeletion(int arr[], int &len, int value);


int main(){
    //array initialize
    int arr[20] = {1,2,3,4,5};

    //determine the size of array
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of array: "<<len<<endl;

    len = 5;  //fixing a length to perform array operation => necessary when performing insertion

    //visit/access each and every element using traverse technique
    arrayTraverse(arr, len);

    //accessing a single element using index
    int index = 0;
    cout<<"Item in index "<<index<<": "<<arr[index]<<endl;

    //searching an element for it index number using linear search
    int target;
    cout << "Enter the value to search for : ";
    cin >> target;
    index = arraySearch(arr, len, target);
    if(index != -1){ 
        cout<<"Found! at index: "<<index<<endl;
    }else{
        cout<<"Not Found!"<<endl;
    }

    //new value insertion in a given position
    cout<<"Insert index: ";
    cin>>index;
    cout<<"Insert value: ";
    int newValue;
    cin>>newValue;
    arrayInsertion(arr, len, index, newValue);

    //update an array value
    int value;
    cout<<"Insert a value to be update: ";
    cin>>value;
    cout<<"Insert a value to update with: ";
    cin>>newValue;
    arrayUpdate(arr, len, value, newValue);

    //delete a specific value(frequency = 1) from array
    cout <<"Delete which item? ";
    cin>>value;
    arrayDeletion(arr, len, value);
    return 0;
}

void arrayTraverse(int arr[], int len){
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int arraySearch(int arr[], int len, int target){    //using linear/brute-force search  <> search vale => key/target
    for(int i=0; i<len; i++){
        if(target == arr[i]){
            return i;       //when found
        }
    }
    return -1;          //when not found
}

int arrayBinarySearch(int arr[], int len, int target){
    int low = 0, mid, high = len-1;
    while(low<=high){
        mid = low + (high-low)/2;
        if(arr[mid]>target){
            mid = high-1;
        }else if(arr[mid]<target){
            mid = low+1;
        }else{
            return mid;
        }
    }
    return -1;    //not found
}

void arrayInsertion(int arr[], int &len, int index, int value){
    if(index>len){  //check if the value can be insert to that index or not
        cout<<"Error! Index is greater than the length"<<endl;
        return;
    }

    cout<<"Befor insertion array is: "; //optional
    arrayTraverse(arr, len);

    for(int i=len; i>index; i--){
        arr[i]=arr[i-1];           //shifting values from last to target index 
    }
    arr[index] = value; //then insert new value
    len++;

    cout<<"After insertion new array is: "; //optional 
    arrayTraverse(arr, len);
}

void arrayUpdate(int arr[], int len, int value, int newValue){     //update array by value
    int index = arrayBinarySearch(arr, len, value);
    if (index == -1) {
        cout<<"Not found value to update"<<endl;
        return;
    }
    arr[index] = newValue;
    cout<<"After updating the array: ";
    arrayTraverse(arr, len);
}

void arrayDeletion(int arr[], int &len, int value){
    int index = arrayBinarySearch(arr, len, value);
    if(index == -1){    //check if the value is in array or not
        cout<<"Value is not in array!"<<endl;
        return;
    }
    
    cout<<"Before deletion array: "; //optional
    arrayTraverse(arr, len);

    for(int i=index;  i<len; i++){
        arr[i]=arr[i+1];
    }
    len--;

    cout<<"After deletion array: "; //optional
    arrayTraverse(arr, len);
}
