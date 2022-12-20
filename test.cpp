#include<iostream>
using namespace std;
string gear[3];
void movegear(int g,int d){
	if(d==1){
		//char tmp=gear[g][7];
		for(int i=1;i<8;i++){
			char tmp=gear[g][i-1];
			cout<<tmp;
			gear[g][i]=tmp;
		}
		//gear[g][0]=tmp;
	}
	else{
		char tmp=gear[g][0];
		for(int i=0;i<7;i++){
			gear[g][i]=gear[g][i+1];
		}
		//gear[g][7]=tmp;
	}
}
int main(void){
    cin>>gear[0];
    movegear(0,1);
    cout<<gear[0]<<'\n';
    //movegear(0,-1);
    //cout<<gear[0];
    return 0;
}