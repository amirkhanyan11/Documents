#include <iostream>
#include <string>
#include <fstream>
std::string add_something(std::string);
std::string replace_character(std::string, char);
int word_count(std::string);
int character_count(std::string);
void stats(std::ifstream&);

int main() {


    std::ifstream file;

    file.open("text.txt");

    stats(file);
    
    file.close();

   
    return 0;
}

void stats(std::ifstream& file) {

    std::string current;

    int linesCount = 0, wordCount = 0, charCount = 0;

    while(!file.eof()) {
        std::getline(file, current);
        wordCount += word_count(current);
        linesCount++;
        charCount += character_count(current);
    }

    std::cout << "Lines : " << linesCount << std::endl; 
    std::cout << "Words : " << wordCount << std::endl;
    std::cout << "Symbols : " << charCount << std::endl;


    return;

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
        if((i > 0) && (str[i] == ' ') && (str[i - 1] != ' ')) {
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



