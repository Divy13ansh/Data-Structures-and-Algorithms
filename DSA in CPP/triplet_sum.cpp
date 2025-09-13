#include<iostream>

using namespace std;
int main(){
    int arr[9] = {1,3,5,7,9,2,1,3,4};
    int n = 9;
    int target = 8;
    for(int i = 0;i<n;i++){
        int left = 0;
        int right = n-1;
        while(left < right){
            if(arr[left]+arr[right]+arr[i] == target){
                cout<<left<<"\t"<<right<<"\t"<<i<<endl;
                exit(1);
            }
            else if(arr[left]+arr[right]+arr[i] < target){
                left++;
            }
            else{
                right--;
            }
        }
    }
    cout<<"Not found";
}