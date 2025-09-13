#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[3][3]= {{0, 0, 3}, {4, 0, 6}, {0, 0, 9}};
    vector<vector<int>> v;


    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            vector<int>a;
            if(arr[i][j] != 0){
                a.push_back(i);
                a.push_back(j);
                a.push_back(arr[i][j]);
                v.push_back(a);
            }
        }
    }

    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<3;j++){
            cout<<v[i][j]<<"\t"; 
        }
        cout<<endl;
    }






}