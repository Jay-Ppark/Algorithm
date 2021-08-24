#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	stack<char> front;
	stack<char> back;
	for (int i = 0; i < s.length(); i++){
		front.push(s[i]);
	}
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++){
		char command;
		cin >> command;
		if (command == 'L'){
			if (!front.empty()){
				back.push(front.top());
				front.pop();
			}
		}
		else if (command == 'D'){
			if (!back.empty()){
				front.push(back.top());
				back.pop();
			}
		}
		else if (command == 'B'){
			if (!front.empty()){
				front.pop();
			}
		}
		else if (command == 'P'){
			char templetter;
			cin >> templetter;
			front.push(templetter);
		}
	}
	while (!front.empty()){
		back.push(front.top());
		front.pop();
	}
	while (!back.empty()){
		cout << back.top();
		back.pop();
	}
	return 0;
}