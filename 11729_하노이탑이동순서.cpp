#include<iostream>
using namespace std;
void hanoi(int from,int by,int to,int n){
	if(n==1){
		cout<<from<<' '<<to<<'\n';
		return;
	}
	hanoi(from,to,by,n-1);
	cout<<from<<' '<<to<<'\n';
	hanoi(by,from,to,n-1);
}
int main(void){
	int N;
	cin>>N;
	int tmp=1;
	for(int i=0;i<N;i++){
		tmp=tmp*2;
	}
	cout<<tmp-1<<"\n";
	hanoi(1,2,3,N);
	return 0;
}