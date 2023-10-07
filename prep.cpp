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

int main() {
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int size = sizeof(arr) / sizeof(int);
    cout << xor_on(arr, size) << endl;
    return 0;
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