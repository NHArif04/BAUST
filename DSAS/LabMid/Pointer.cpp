#include<iostream>
using namespace std;

double getAverage(int arr[], int len);

int main(){
    const char* name = "Nahid";   //const char* => string
    const char* fullName[] = {"Nahid","Hasan","Arif"};
    for(int i=0; name[i]!=NULL; i++){
        cout<<name[i];
    }
    cout<<endl;

    for(int i=0; i<sizeof(fullName)/sizeof(fullName[0]); i++){
        cout<<fullName[i]<<" ";
    }
    cout<<endl;

    int values[] = {1,4,16};
    int size = sizeof(values)/sizeof(values[0]);
    double result = getAverage(values, size);
    cout<<"Average of the array is: "<<result<<endl;
    return 0;
}


double getAverage(int* arr, int len){    //array can also be receive as pointer
    double sum = 0;
    for(int i=0; i<len; i++){
        sum+=arr[i];
    }

    return (double)sum/len;
}

int* getPointer(){
    //?
    //
    //!
    return ;
}