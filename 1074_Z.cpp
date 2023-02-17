#include<iostream>
using namespace std;
int findnum(int n,int r,int c){
	if(n==0){
		return 0;
	}
	int half=1;
	for(int i=0;i<n-1;i++){
		half=half*2;
	}
	if(r<half&&c<half){
		return findnum(n-1,r,c);
	}
	else if(r<half&&c>=half){
		return half*half+findnum(n-1,r,c-half);
	}
	else if(r>=half&&c<half){
		return half*half*2+findnum(n-1,r-half,c);
	}
	else{
		return half*half*3+findnum(n-1,r-half,c-half);
	}
}
int main(void){
	int n,r,c;
	cin>>n>>r>>c;
	cout<<findnum(n,r,c);
	return 0;
}