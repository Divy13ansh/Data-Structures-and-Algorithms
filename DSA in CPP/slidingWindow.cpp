#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector<int> arr = {2,1,5,1,3,2};
    int i = 0;
    int k = 3;
    int j = i+k;
    int maxs = arr[0];

    for(int i = 0;j<=arr.size();i++){
        int s = 0;
        for(int it = i;it<j;it++){
            s+=arr[it];
        }
        if(s > maxs) maxs = s;
        j++;
    }
    cout<<maxs;

}