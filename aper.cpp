#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int my_atoi(string);
string code(string);
void redirect(fstream&, fstream&);
string decode(string);


int main(){
	
	cout << decode("A3c1B2") << endl;

	return 0;
}

string code(string source) {

	string res;
	int current_count = 0;
	for(int i = 0; i  < source.length(); i += current_count) {
		current_count = 1;
		char current = source[i];
		for(int j = i + 1; j < source.length(); j++){
			if((i < source.length() - 1) && source[j] == current){
				current_count++;
			}
		}
		res.push_back(current);
		res += to_string(current_count);
	}
	return res;
}

string decode(string source) {

	string res;
	char current_character = '0';
	
	for(int i = 0; i < source.length(); i++) {
		
		if(source[i] < '0' || source[i] > '9') {
			current_character = source[i];
			continue;
		}

		string current_digit;

		for(int j = i; (source[j] >= '0') && (source[j] <= '9'); j++){
			current_digit.push_back(source[j]);
		}

		for(int k = 0; k < my_atoi(current_digit); k++) {
			res.push_back(current_character);
		}

	}

	return res;

}



int my_atoi(string source) {
	int res = 0;
	int exp = source.length() - 1;
	for(int i = 0; i < source.length(); i++, exp--) {
		res += (source[i] - '0') * pow(10, exp);
	}
	return res;
}