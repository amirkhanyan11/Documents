#include <iostream>
#include <cmath>
using namespace std;
void print_binary(int);
void set(int, int);
void reset(int, int);
void bit_swap(int*, int, int);
void reverse_binary(int);
bool two_power(int);
int xor_on(int*, int);
void insertion_sort(int*, int);
void printArr(int*, int);
void bubble(int*, int);
int rec_bubble(int*, int, int, int);

int main() {
    int arr[] = {2, -55, 7, -37, 4, 5, -9, 0, 12, -45, 3, 21, -8, 13, -6, 17, 1, -11, 16, -23};
    int size = sizeof(arr) / sizeof(int);
    

    printArr(arr, size);
    rec_bubble(arr, size, 0, 1);
    printArr(arr, size);
    return 0;
}

int rec_bubble(int* arr, int size, int i, int j) {
    if(i == size - 1){
        return 0;
    }
    if(j == size) {
        return rec_bubble(arr, size, i + 1, 1);
    }
    if(arr[j - 1] > arr[j]) {
        swap(arr[j - 1], arr[j]);
    }
    return rec_bubble(arr, size, i, j + 1);
}

void bubble(int* arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        bool flag = true;
        for(int j = 1; j < size; j++) {
            if(arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                flag = false;
            }
        }
        if(flag) {
            return;
        }
    }
    return;
}

void insertion_sort(int* arr, int size) {
    for(int i = 1; i < size; i++) {
        int current = arr[i];
        int j = i - 1;
        while(arr[j] > current && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    return;
} 

void printArr(int* arr, const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;

    return;
}


int xor_on(int* arr, int size) {
    int n = 0;
    for(int i = 0; i < size; i++) {
        n ^= arr[i];
    }
    return n;
}

void print_binary(int num) {

    int shift = (1 << 16);

    while(shift > 0) {
        if(num & shift) {
            cout << '1';
        }
        else {
            cout << '0';
        }
        shift >>= 1;   
    }
    cout << endl;
    return;
}

void set(int num, int i) {
    print_binary(num);
    int shift = (1 << i);
    num |= shift;
    print_binary(num);
    return;
}

void reset(int num, int i) {

    int stop = pow(2, i);

    int shift = (1 << 16);

    while(shift > 0) {
        if(num & shift && shift != stop) {
            cout << '1';
        }
        else {
            cout << '0';
        }
        shift >>= 1;   
    }
    cout << endl;
    return;
}



void bit_swap(int* num, int i, int j) {
    int tmp = *num;
    if(i < 0 || j > 32) {
        return;
    }
    bool first = (tmp & (1 << i));
    bool second = (tmp & (1 << j));

    if(first == second) {
        // print_binary(tmp);
    }

    else {
        tmp ^= (1 << i);
        tmp ^= (1 << j);
        // print_binary(tmp);
    }

    *num = tmp;

    return;

}



void reverse_binary(int num) {
    int i = 0;
    int j = 31;

    bool i_flag = (num & (1 << i));
    bool j_flag = (num & (1 << j));

    while(i < j) {
        bit_swap(&num, i, j);
        i++;
        j--;
    }
    print_binary(num);
    return;
}

bool two_power(int num) {
    return (!((num) & (num - 1)));
}
