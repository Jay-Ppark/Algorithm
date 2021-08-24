#include<iostream>
#include<string>
#include<list>
using namespace std;
int main(void){
	int testcase;
	string s;
	cin >> s;
	cin >> testcase;
	list<char> editor(s.begin(), s.end());
	auto cursor = editor.end();
	for (int i = 0; i < testcase; i++){
		char command;
		cin >> command;
		if (command == 'L'){
			if (cursor != editor.begin()){
				cursor--;
			}
		}
		else if (command == 'D'){
			if (cursor != editor.end()){
				cursor++;
			}
		}
		else if (command == 'B'){
			if (cursor != editor.begin()){
				cursor--;
				cursor = editor.erase(cursor);
			}
		}
		else if (command == 'P'){
			char templetter;
			cin >> templetter;
			editor.insert(cursor, templetter);
		}
	}
	for (auto &result:editor){
		cout << result;
	}
	return 0;
}