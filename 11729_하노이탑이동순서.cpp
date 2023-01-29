#include<iostream>
using namespace std;
void hanoi(int n,int start,int bypass,int to){
	if(n==1){
		cout<<start<<" "<<to<<'\n';
		return;
	}
	hanoi(n-1,start,to,bypass);
	cout<<start<<" "<<to<<'\n';
	hanoi(n-1,bypass,start,to);
}
int main(void){
	int n;
	cin>>n;
	cout<<(1<<n)-1<<'\n';
	hanoi(n,1,2,3);
	return 0;
}