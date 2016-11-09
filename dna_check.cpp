#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <vector>
#include <stdexcept>

using namespace std;

void findMaxSubstring(string generatedText, int k){
	map<string, pair <int, vector<int> > > m;
	string temp;
    int len = generatedText.length();
    len -= k;

	for (int j = 0; j < len - k; ++j){
		temp = generatedText.substr(j, k);
		if (m.find(temp) == m.end()){

			for (int p = 0; p < len; ++p){ 
				
				if (generatedText.substr(p, k) == temp){
					if (m.find(temp) == m.end())
						m[temp].first = 1;
					else
						++m[temp].first;

					m[temp].second.push_back(p);
				}
			}
		}
	}

    vector<int> blankV;
	pair <string, pair <int, vector <int> > > max (" ", make_pair(0, blankV));

	for (map<string, pair <int, vector<int> > >::iterator i = m.begin(); i != m.end(); ++i){
		if (i->second.first > max.second.first)
			max = *i;
	}

	cout <<max.first << endl;
}
int main(int argc, char *argv[]){
	int k, length;
	string generatedText;
	ifstream infile;
	infile.open(argv[1]);
	infile >> generatedText;
	infile.close();
	k = 100;
	findMaxSubstring(generatedText, k);
	return 0;
}
