#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(nums[j] < pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[right]);
    return i + 1;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    int pivotIndex = partition(arr, 0, arr.size() - 1);
    cout << "Pivot Index: " << pivotIndex << endl;
    cout << "Array after partitioning: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}