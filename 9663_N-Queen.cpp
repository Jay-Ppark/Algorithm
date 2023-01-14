#include<iostream>
using namespace std;
int N;
int queen[15];
int answer;
bool check(int q){
	for(int i=0;i<q;i++){
		if(queen[i]==queen[q]||abs(i-q)==abs(queen[i]-queen[q])){
			return false;
		}
	}
	return true;
}
void movequeen(int cnt){
	if(cnt==N){
		answer++;
		return;
	}
	for(int i=0;i<N;i++){
		queen[cnt]=i;
		if(check(cnt)){
			movequeen(cnt+1);
		}
	}
}
int main(void){
	cin>>N;
	movequeen(0);
	cout<<answer;
	return 0;
}