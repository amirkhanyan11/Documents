#include <iostream>
#define SIZE 10

int arr[SIZE];

void fillArr(int arr[SIZE]){
    for(int i = 0; i < SIZE; i++){
        arr[i] = rand() % 20 + 1;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return;
}

bool isEven(int num){
    return (num % 2 == 0) ? true : false;
}

int apply(int arr[SIZE], bool(*isEvenptr)(int)){
    int count = 0;
    for(int i = 0; i < SIZE; ++i){
        if(isEvenptr(arr[i])){
            count++;
        }
    }
    return count;
}

int split(const char* str){
    int wordCount = 0;
    bool wordValid = false;
    while(*str != '\0'){
        if(*str != ' '){
            wordValid = true;
        }
        if(wordValid && (*str == ' ')){
            wordCount++;
            wordValid = false;
        }
        ++str;
    }
    return (wordValid) ? ++wordCount : wordCount;
}

int fifth(int* ptr, int* ptr1){
    *ptr += 1;
    *ptr1 = *ptr;
    return ++*ptr1;
}

void foo(int* target, char c1, char c2, short sh){
    char* temp_1 = (char*) target;
    *temp_1 = c1;
    *(++temp_1) = c2;
    short* temp_2 = (short*) (++temp_1);
    *temp_2 = sh;
    return;
}

char* myStrcat(char* result, const char* target){
    bool start = false;
    char* returnRes = result;
    while(*target != '\0'){
        if(*result == '\0'){
            start = true;
        }
        if(start){
            *result = *target;
            ++target;
        }
        ++result;
    }
    *result = '\0';
    return returnRes;
}

int main(){
    

    //         void foo()....

    // int num = 1;
    // char c1 = 'a';
    // char c2 = 'b';
    // short sh = 888;

    // char* ptr = (char*)&num;

    // foo(&num, c1, c2, sh);

    // std::cout << *ptr << ", " << *(++ptr) << ", " << *((short*)(++ptr)) << std::endl;

    
    
    //                 Concat
    
    // char result[20] = "hello ";
    // const char* target = "world!";

    // std::cout << myStrcat(result, target) << std::endl;



    //       Apply


    // bool(*validity)(int) = isEven;

    // fillArr(arr);

    // std::cout << "Evens count: " << apply(arr, validity) << std::endl;

    return 0;
}