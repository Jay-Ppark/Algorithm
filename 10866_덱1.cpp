#include<iostream>
#include<deque>
#include<string>
using namespace std;
deque <int> dq;
string command;
int main(void){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> command;
		if (command.compare("push_front") == 0){
			int temp;
			cin >> temp;
			dq.push_front(temp);
		}
		else if (command.compare("push_back") == 0){
			int temp;
			cin >> temp;
			dq.push_back(temp);
		}
		else if (command.compare("pop_front") == 0){
			if(dq.empty()){
                cout<<"-1"<<'\n';
            }
            else{
                cout<<dq.front()<<'\n';
                dq.pop_front();
            }
		}
		else if (command.compare("pop_back") == 0){
			if(dq.empty()){
                cout<<"-1"<<'\n';
            }
            else{
                cout<<dq.back()<<'\n';
                dq.pop_back();
            }
		}
		else if (command.compare("size") == 0){
			cout << dq.size() << '\n';
		}
		else if (command.compare("empty") == 0){
			cout << dq.empty() << '\n';
		}
		else if (command.compare("front") == 0){
			if(dq.empty()){
                cout<<"-1"<<'\n';
            }
            else{
                cout<<dq.front()<<'\n';
            }
		}
		else if (command.compare("back") == 0){
			if(dq.empty()){
                cout<<"-1"<<'\n';
            }
            else{
                cout<<dq.back()<<'\n';
            }
		}
	}
	return 0;
}