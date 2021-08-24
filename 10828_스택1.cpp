#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack <int> v;
string command;
int main(void){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> command;
		if (command.compare("push") == 0){
			int temp;
			cin >> temp;
			v.push(temp);
		}
		else if (command.compare("pop") == 0){
			if(v.empty()){
                cout<<"-1"<<'\n';
            }
            else{
                cout<<v.top()<<'\n';
                v.pop();
            }
		}
		else if (command.compare("size") == 0){
			cout << v.size() << '\n';
		}
		else if (command.compare("empty") == 0){
			cout << v.empty() << '\n';
		}
		else if (command.compare("top") == 0){
			if(v.empty()){
                cout<<"-1"<<'\n';
            }
            else{
                cout<<v.top()<<'\n';
            }
		}
	}
	return 0;
}