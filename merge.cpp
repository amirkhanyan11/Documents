#include <iostream>
#include <vector>
void printArr(vector<int>&);
void mergeSort(vector<int>&);
void merge(vector<int>&, vector<int>&, vector<int>&);
using namespace std;


int main() {

    vector<int> arr = {2, -55, 7, -37, 4, 5, -9, 0, 12, -45, 3, 21, -8, 13, -6, 17, 1, -11, 16, -23};

    printArr(arr);

    mergeSort(arr);

    printArr(arr);

    return 0;
}



void printArr(vector<int>& arr) {

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << "  ";
    }

    std::cout << std::endl;

    return;
}

void merge(vector<int>& left, vector<int>& right, vector<int>& arr) {

    int l_length = arr.size() / 2;
    int r_length = arr.size() - l_length;

    int i = 0, l = 0, r = 0;

    while((l < l_length) && (r < r_length)) {

        if(left[l] < right[r]) {
            
            arr[i++] = left[l++];
        }

        else {
            arr[i++] = right[r++];
        }
    }

    while(l < l_length) {
        arr[i++] = left[l++];   
    }

    while(r < r_length) {
        arr[i++] = right[r++];
    }

    return;
}


void mergeSort(vector<int>& arr) {

    int length = arr.size();

    if(length <= 1) {
        return;
    }

    int middle = length / 2;

    vector<int> left_arr;
    vector<int> right_arr;

    for(int i = 0; i < length; i++) {

        if(i < middle) {
            left_arr.push_back(arr[i]);
        }

        else {
            right_arr.push_back(arr[i]);
        }
        
    }

    mergeSort(left_arr);
    mergeSort(right_arr);
    merge(left_arr, right_arr, arr);
}

