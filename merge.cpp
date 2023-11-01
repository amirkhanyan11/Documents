#include <iostream>
#include <vector>
using std::vector, std::cout, std::endl;
template<typename T>
void printArr(vector<T>&);
template<typename T>
void mergeSort(vector<T>&);
template<typename T>
void merge(vector<T>&, vector<T>&, vector<T>&);



int main() {

    vector<int> arr = {2, -55, 7, -37, 4, 5, -9, 0, 12, -45, 3, 21, -8, 13, -6, 17, 1, -11, 16, -23};

    printArr<int>(arr);

    mergeSort<int>(arr);

    printArr(arr);


    int&& r = 7;

    r = 0;

    cout << r << endl;

    return 0;
}


template<typename T>
void printArr(vector<T>& arr) {

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << "  ";
    }

    std::cout << std::endl;

    return;
}

template<typename T>
void merge(vector<T>& left, vector<T>& right, vector<T>& arr) {

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

template<typename T>
void mergeSort(vector<T>& arr) {

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

    mergeSort<T>(left_arr);
    mergeSort<T>(right_arr);
    merge<T>(left_arr, right_arr, arr);
}


// #include <stdio.h>


// void bubble_sort(int argc, char* argv[]) {

//     for(int i = 1; i < argc - 1; i++) {

//         for(int j = i + 1; j < argc; j++) {

//             if(argv[j - 1] > argv[j]) {

//                 char* temp = argv[j - 1];

//                 argv[j - 1] = argv[j];

//                 argv[j] = temp;

//             }
//         }
//     }
// }

// int main(int argc, char* argv[]) {

//     bubble_sort(argc, argv);

//     for(int i = 0; i < argc; i++) {

//         printf("%s ", argv[i]);

//     }

//     printf("\n");

//     return 0;
// }





// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// void bubble_sort(int argc, char* argv[]) {

//     int i = 0;

//     while (i < argc - 1) {

//         int j = i + 1;

//         while (j < argc - i) {

//             if (strcmp(argv[j - 1], argv[j]) > 0) {

//                 char* temp = argv[j - 1];
//                 argv[j - 1] = argv[j];
//                 argv[j] = temp;

//             }

//             j++;

//         }
//         i++;
//     }
// }

// int main(int argc, char* argv[]) {

//     bubble_sort(argc, argv);

//     for (int i = 1; i < argc; i++) {
        
//         int length = 0;

//         char* t_arg = argv[i];

//         while(*(argv[i])) {
//             length++, argv[i]++;
//         }

//         write(1, t_arg, length);

//         write(1, "  ", 1);

//     }

//     write(1, "\n", 1);
    
//     return 0;
// }
