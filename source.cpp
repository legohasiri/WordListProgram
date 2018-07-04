#include <fstream>
#include <sstream>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main() {
	string buf;
	vector<string> word;
	vector<string> index;
	ifstream ifs("List.txt");
	if (ifs.fail()) {
		exit(-1);
	}
	char* a = 0, *b = 0;
	while (getline(ifs, buf,',')) {
		static int count = 0;
		
		if (count == 0 || count % 2 == 0) {
			word.push_back(buf);
		}
		else {
			index.push_back(buf);
		}
		count++;
	}
	for (auto& i : word) {
		cout << i << endl;
		
		static int count = 0;
		if (_getch() == 0x0d) {
			cout << index.at(count) << endl;
		}
		while(_getch()==0x0d){ }
		count++;
	}
}
