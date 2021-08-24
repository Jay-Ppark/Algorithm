#include<iostream>
#include<queue>
#include<string>
using namespace std;
queue <int> q;
string command;
int main(void){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> command;
		if (command.compare("push") == 0){
			int temp;
			cin >> temp;
			q.push(temp);
		}
		else if (command.compare("pop") == 0){
			if(q.empty()){
                cout<<"-1"<<'\n';
            }
            else{
                cout<<q.front()<<'\n';
                q.pop();
            }
		}
		else if (command.compare("size") == 0){
			cout << q.size() << '\n';
		}
		else if (command.compare("empty") == 0){
			cout << q.empty() << '\n';
		}
		else if (command.compare("front") == 0){
			if(q.empty()){
                cout<<"-1"<<'\n';
            }
            else{
                cout<<q.front()<<'\n';
            }
		}
		else if (command.compare("back") == 0){
			if(q.empty()){
                cout<<"-1"<<'\n';
            }
            else{
                cout<<q.back()<<'\n';
            }
		}
	}
	return 0;
}