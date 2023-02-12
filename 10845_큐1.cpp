#include<iostream>
#include<queue>
using namespace std;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	queue<int> Q;
	for(int i=0;i<N;i++){
		string order;
		cin>>order;
		if(order=="push"){
			int tmp;
			cin>>tmp;
			Q.push(tmp);
		}
		else if(order=="pop"){
			if(Q.empty()){
				cout<<"-1\n";
			}
			else{
				cout<<Q.front()<<'\n';
				Q.pop();
			}
		}
		else if(order=="size"){
			cout<<Q.size()<<'\n';
		}
		else if(order=="empty"){
			if(Q.empty()){
				cout<<"1\n";
			}
			else{
				cout<<"0\n";
			}
		}
		else if(order=="front"){
			if(Q.empty()){
				cout<<"-1\n";
			}
			else{
				cout<<Q.front()<<'\n';
			}
		}
		else if(order=="back"){
			if(Q.empty()){
				cout<<"-1\n";
			}
			else{
				cout<<Q.back()<<'\n';
			}
		}
	}
	return 0;
}