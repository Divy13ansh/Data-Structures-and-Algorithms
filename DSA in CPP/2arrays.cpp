#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {5,6,7,8,9};
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<b.size();j++){
            if(a[i] == b[j]){
                cout<<"Yes "<< b[j];
                exit(1);
            }
        }
    }
    cout<<"No";
}