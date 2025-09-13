#include<iostream>

using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int target;
    int flag = 0;
    target = 5;
    for(int i = 0;i < sizeof(arr)/sizeof(arr[0]);i++){
        if(arr[i] == target){
            cout<< "Found at "<< i;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout<< "Target not found in array.";
    }
}