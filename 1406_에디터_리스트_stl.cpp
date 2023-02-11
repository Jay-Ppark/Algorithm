#include<iostream>
#include<string>
#include<list>
using namespace std;
int main(void){
	string s;
	cin>>s;
	list<char> l;
	for(int i=0;i<s.size();i++){
		l.push_back(s[i]);
	}
	auto cursor=l.end();
	int order;
	cin>>order;
	for(int t=0;t<order;t++){
		char c;
		cin>>c;
		if(c=='P'){
			char tmp;
			cin>>tmp;
			l.insert(cursor,tmp);
		}
		else if(c=='L'){
			if(cursor!=l.begin()){
				cursor--;
			}
		}
		else if(c=='D'){
			if(cursor!=l.end()){
				cursor++;
			}
		}
		else if(c=='B'){
			if(cursor!=l.begin()){
				cursor--;
				cursor=l.erase(cursor);
			}
		}
	}
	for(auto i:l){
		cout<<i;
	}
	return 0;
}