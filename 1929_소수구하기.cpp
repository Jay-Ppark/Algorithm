#include<iostream>
#include<vector>
using namespace std;
int main(void){
	int startn, endn;
	cin>>startn>>endn;
	vector<bool> isprime(endn+1,true);
	isprime[1]=false;
	for(int i=2;i*i<=endn;i++){
		if(!isprime[i]){
			continue;
		}
		for(int j=i*i;j<=endn;j+=i){
			isprime[j]=false;
		}
	}
	for(int i=startn;i<=endn;i++){
		if(isprime[i]){
			cout<<i<<'\n';
		}
	}
	return 0;
}