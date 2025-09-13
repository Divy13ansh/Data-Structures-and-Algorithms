#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int max = 0;
    for(int i = 0;i<arr.size();i++){
        for(int j = i;j<arr.size();j++){
            if(arr[i] - arr[j] > abs(max)){
                cout<< arr[i] <<"\t" << arr[j];
            }
        }
    }
    
}