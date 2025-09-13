#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a = {15,1,5,5,5};
    for(int i = 0;i<a.size();i++){
        int sl = 0, sr = 0;
        for(int j = 0; j < i;j++){
            sl += a[j];
        }
        for(int j = i+1; j < a.size();j++){
            sr+= a[j];
        }
        if(sl == sr){
            cout<< "Equilib at "<< i;
            exit(1);
        }
    }
    cout<< "Equilib not found";
}