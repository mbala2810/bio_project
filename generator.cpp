#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <map>
#include <vector>
//#include <type_traits.h>
#include <stdexcept>

using namespace std;

string generateSequence(int k){
	string s(k, ' ');
	int temp;
	srand (time(NULL));

	for (int i = 0; i < k; ++i){
		temp = rand() % 4;
		switch (temp){
			case 0:
				s[i] = 'G';
				break;
			case 1:
				s[i] = 'C';
				break;
			case 2:
				s[i] = 'A';
				break;
			case 3:
				s[i] = 'T';
				break;
		}
	}
	cout<<s;	
	return s;
}
int main(int argc, char *argv[]){
	int k, length;
	string generatedText;
	length = 1000;
	generatedText = generateSequence(length);
	return 0;
}
