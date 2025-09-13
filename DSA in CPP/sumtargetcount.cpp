#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a = {1,2,3,2,1};
    int target = 4;
    int c = 0;
    for(int i = 0; i<a.size();i++){
        for(int j = i+1;j<a.size();j++){
            if(a[i] + a[j] == target){
                c++;
            }
        }
    }
    cout<<c;
}