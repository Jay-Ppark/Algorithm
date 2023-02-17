#include<iostream>
using namespace std;
int N;
void hanoi(int n,int from,int by,int to){
	if(n==1){
		cout<<from<<' '<<to<<'\n';
		return;
	}
	hanoi(n-1,from,to,by);
	cout<<from<<' '<<to<<'\n';
	hanoi(n-1,by,from,to);
}
int main(void){
	cin>>N;
	int result=1;
	for(int i=0;i<N;i++){
		result=result*2;
	}
	cout<<result-1<<'\n';
	hanoi(N,1,2,3);
	return 0;
}