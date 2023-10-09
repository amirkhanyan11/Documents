#include <iostream>
#include <string>
#include <fstream>
std::string add_something(std::string);
std::string replace_character(std::string, char);


int main() {

    std::ofstream write_file;

    write_file.open("my_file.txt");

    if(!write_file.is_open()) {
        return -1;
    }

    write_file << "appended" << std::endl;

    write_file.close();


    std::ifstream my_file;
    my_file.open("my_file.txt");
    std::string str;

    if(!my_file.is_open()) {
        return -1;
    }

    while(!my_file.eof()) {
        std::getline(my_file, str);
        std::cout << replace_character(str, 'a') << " ";
    }

    std::cout << std::endl;
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

