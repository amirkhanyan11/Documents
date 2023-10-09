#include <iostream>
#include <string>
#include <fstream>
std::string add_something(std::string);
std::string replace_character(std::string, char);
int word_count(std::string);
int character_count(std::string);
void stats(std::string);

int main() {

    // std::ofstream change;

    // change.open("changed.txt");

    // std::ifstream my_file;
    // my_file.open("my_file.txt");
    // std::string str;

    // if(!my_file.is_open()) {
    //     return -1;
    // }

    // while(!my_file.eof()) {
    //     std::getline(my_file, str);
    //     change << replace_character(str, 'a') << std::endl;
    // }

    // std::cout << std::endl;

    // my_file.close();
    // change.close();

    std::ifstream my_file;

    std::string current;

    std::string res;



    my_file.open("my_file.txt");

    while(!my_file.eof()) {
        std::getline(my_file, current);
        res += current;
    }

    std::cout << res << std::endl;

    stats(res);


    my_file.close();

    return 0;
}


std::string add_something(std::string str) {
    return (str + " qwerty");
}

std::string replace_character(std::string str, char key) {
    for(int i = 0; i < str.length(); ++i) {
        if(str[i] == key) {
            str[i] = '$';
        }
    }
    return str;
} 


int word_count(std::string str) {
    int count = 0;
    bool word_flag = false;
    for(int i = 0; i < str.length(); ++i) {
        if(str[i] != ' ') {
            word_flag = true;
        }
        if(str[i] == ' ') {
            count++;
            word_flag = false;
        }
    }
    return (word_flag) ? ++count : count;
}

int character_count(std::string str) {
    int count = 0;
    for(int i = 0; i < str.length(); ++i) {
        if(str[i] != ' '){
            count++;
        }
    }
    return count;
}

void stats(std::string file) {

    // std::cout << "Lines : " << linesCount << std::endl; 
    std::cout << "Words : " << word_count(file) << std::endl;
    std::cout << "Symbols : " << character_count(file) << std::endl;

    return;

} 
