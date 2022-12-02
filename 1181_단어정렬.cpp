#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v;
bool comp(string a,string b){
	if(a.length()==b.length()){
		return a<b;
	}
	else{
		return a.length()<b.length();
	}
}
int main(void){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		string tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<N;i++){
		if(i==0){
			cout<<v[i]<<"\n";
		}
		else if(i>=1){
			if(v[i]==v[i-1]){
				continue;
			}
			else{
				cout<<v[i]<<"\n";
			}
		}
	}
	return 0;
}