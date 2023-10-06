#include <iostream>

int arr[] = {2, -55, 7, -37, 4, 5, -9, 0, 12, -45, 3, 21, -8, 13, -6, 17, 1, -11, 16, -23};
int arr2[] = {2,  -55,  7,  -37,  4,  5};
const int SIZE = (sizeof(arr2) / sizeof(int));

void printArr(int arr[SIZE]);
int partition(int arr[SIZE], int, int);
void qsort(int arr[SIZE], int low = 0, int high = SIZE - 1);
void insertion_sort(int arr[SIZE]);
void bubble_sort(int arr[SIZE]);
int recursive_bubble_sort(int arr[SIZE], int i = 0, int j = 1);
void selection_sort(int*, const int)


int main() {

    printArr(arr2);

    recursive_bubble_sort(arr2, SIZE);

    printArr(arr2);

    return 0;
}

void printArr(int arr[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;

    return;
}

int partition(int arr[SIZE], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            std::swap(arr[++i], arr[j]);
        }
    }
    std::swap(arr[++i], arr[high]);
    return i;
}

void qsort(int arr[SIZE], int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        qsort(arr, low, --pivot);
        qsort(arr, ++pivot, high);
    }
    return;
}

void bubble_sort(int arr[SIZE]) {
    for(int i = 0; i < SIZE - 1; i++) {
        bool flag = true;
        for(int j = 1; j < SIZE; j++) {
            if(arr[j - 1] > arr[j]) {
                std::swap(arr[j - 1], arr[j]);
                flag = false;
            }
        }
        if(flag) {
            return;
        }
    }
    return;
}

int recursive_bubble_sort(int arr[SIZE], int i, int j) {
    if(i == SIZE - 1) {
        return 0;
    }
    if(j == SIZE) {
        return recursive_bubble_sort(arr, i + 1, 1);
    }
    if(arr[j - 1] > arr[j]) {
        std::swap(arr[j - 1], arr[j]); 
    }
    return recursive_bubble_sort(arr, i, j + 1);
}

void insertion_sort(int arr[SIZE]) {
    for(int i = 1; i < SIZE; i++) {
        int current = arr[i];
        int j = (i - 1);
        while(arr[j] > current && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    return;
}

void selection_sort(int* arr, const int SIZE) {
    for(int i = 0; i < SIZE - 1; i++) {
        int smallest_index = i;
        for(int j = i + 1; j < SIZE; j++) {
            if(arr[j] < arr[smallest_index]) {
                smallest_index = j;
            }
        }
        std::swap(arr[i], arr[smallest_index]);
    }
    return;
}


/*
void merge(int arr[], int left[], int right[], const int length) {
    int leftSize = length / 2;
    int rightSize = length - leftSize;

    int i = 0;
    int l = 0;
    int r = 0;

    while(l < leftSize && r < rightSize) {
        if(left[l] < right[r]) {
            arr[i] = left[l];
            i++;
            l++;
        }
        else{
            arr[i] = right[r];
            i++;
            r++;
        }
    }
    while (l < leftSize) {
        arr[i] = left[l];
        ++i;
        ++l;
    }
    while (r < rightSize) {
        arr[i] = right[r];
        ++i;
        ++r;
    }
    return;
}


void merge_sort(int arr[], const int length) {
    if(length <= 1) {
        return;
    }

    int middle = length / 2;

    int* left = new int[middle];
    int* right = new int[length - middle];

    int i = 0; // left
    int j = 0; // right

    for(; i < length; i++) {
        if(i < middle) {
            left[i] = arr[i];
        }
        else {
            right[j] = arr[j];
            j++;
        }
    }

    merge_sort(left, SIZE);
    merge_sort(right, SIZE);
    merge(arr, left, right, length);

}

*/
