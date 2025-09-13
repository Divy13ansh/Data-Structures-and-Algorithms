#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>a = {1,3,5,7,9,11};
    vector<int>b = {2,4,6,8};

    vector<int>c;
    int i = 0;
    int j = 0;
    int k = 0;
    while(c.size() != a.size()+b.size()){
        if(i < a.size() && a[i]<=b[j]){
            c.push_back(a[i]);
            i++;
            k++;
            continue;
        }
        if(j < b.size() && a[i]> b[j]){
            c.push_back(b[j]);
            j++;
            k++;
        }
    }
    for(int i = 0;i<c.size();i++){
        cout<<c[i]<<"\t";
    }

}