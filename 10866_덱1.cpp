#include<iostream>
#include<deque>
using namespace std;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	deque<int> DQ;
	for(int i=0;i<N;i++){
		string order;
		cin>>order;
		if(order=="push_front"){
			int tmp;
			cin>>tmp;
			DQ.push_front(tmp);
		}
		else if(order=="push_back"){
			int tmp;
			cin>>tmp;
			DQ.push_back(tmp);
		}
		else if(order=="pop_front"){
			if(DQ.empty()){
				cout<<"-1\n";
			}
			else{
				cout<<DQ.front()<<'\n';
				DQ.pop_front();
			}
		}
		else if(order=="pop_back"){
			if(DQ.empty()){
				cout<<"-1\n";
			}
			else{
				cout<<DQ.back()<<'\n';
				DQ.pop_back();
			}
		}
		else if(order=="size"){
			cout<<DQ.size()<<"\n";
		}
		else if(order=="empty"){
			if(DQ.empty()){
				cout<<"1\n";
			}
			else{
				cout<<"0\n";
			}
		}
		else if(order=="front"){
			if(DQ.empty()){
				cout<<"-1\n";
			}
			else{
				cout<<DQ.front()<<'\n';
			}
		}
		else if(order=="back"){
			if(DQ.empty()){
				cout<<"-1\n";
			}
			else{
				cout<<DQ.back()<<'\n';
			}
		}
	}
	return 0;
}