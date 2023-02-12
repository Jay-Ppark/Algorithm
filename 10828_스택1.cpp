#include<iostream>
#include<stack>
using namespace std;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> S;
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		string order;
		cin>>order;
		if(order=="push"){
			int tmp;
			cin>>tmp;
			S.push(tmp);
		}
		else if(order=="pop"){
			if(S.empty()){
				cout<<"-1\n";
			}
			else{
				int t=S.top();
				S.pop();
				cout<<t<<'\n';
			}
		}
		else if(order=="size"){
			cout<<S.size()<<'\n';
		}
		else if(order=="empty"){
			if(S.empty()){
				cout<<"1\n";
			}
			else{
				cout<<"0\n";
			}
		}
		else if(order=="top"){
			if(S.empty()){
				cout<<"-1\n";
			}
			else{
				cout<<S.top()<<'\n';
			}
		}
	}
	return 0;
}