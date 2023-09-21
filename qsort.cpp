#include <iostream>


int arr[] = {2, -55, 7, -37, 4, 5, -9, 0, 12, -45, 3, 21, -8, 13, -6, 17, 1, -11, 16, -23};


const int SIZE = sizeof(arr) / sizeof(int);

void printArr(int arr[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;

    return;
}

int partition(int arr[SIZE], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[++i], arr[high]);
    return i;
}

void myQsort(int arr[SIZE], int low = 0, int high = SIZE - 1){
    if(low < high){
        int pivot = partition(arr, low, high);
        myQsort(arr, low, --pivot);
        myQsort(arr, ++pivot, high);
    }
    return;

}

int main(){
    printArr(arr);
    myQsort(arr);
    printArr(arr);
    return 0;
}
