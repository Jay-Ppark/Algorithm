#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<char> s;
void checkpp(){
	bool check=true;
	while(check&&s.size()>=4){
		if(s[s.size()-1]=='P'&&s[s.size()-2]=='A'&&s[s.size()-3]=='P'&&s[s.size()-4]=='P'){
			s.pop_back();
			s.pop_back();
			s.pop_back();
			s.pop_back();
			s.push_back('P');
		}
		else{
			check=false;
		}
	}
}
int main(void){
	string ppap;
	cin>>ppap;
	for(int i=0;i<ppap.length();i++){
		s.push_back(ppap[i]);
		if(s.size()>=4){
			checkpp();
		}
	}
	if(s.size()==1&&s.back()=='P'){
		cout<<"PPAP";
	}
	else{
		cout<<"NP";
	}
	return 0;
}