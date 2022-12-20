#include<iostream>
#include<string>
using namespace std;
string gear[4];
void movegear(int g,int d){
	string tmp=gear[g];
	if(d==1){
		for(int i=0;i<8;i++){
			gear[g][i]=tmp[(i+7)%8];
		}
	}
	else{
		for(int i=0;i<8;i++){
			gear[g][i]=tmp[(i+1)%8];
		}
	}
}
void checkmove(int g,int d){
	if(g==0){
		if(gear[0][2]!=gear[1][6]){
			if(gear[1][2]!=gear[2][6]){
				if(gear[2][2]!=gear[3][6]){
					movegear(0,d);
					movegear(1,d*-1);
					movegear(2,d);
					movegear(3,d*-1);
				}
				else{
					movegear(0,d);
					movegear(1,d*-1);
					movegear(2,d);
				}
			}
			else{
				movegear(0,d);
				movegear(1,d*-1);
			}
		}
		else{
			movegear(0,d);
		}
	}
	else if(g==1){
		if(gear[1][6]!=gear[0][2]){
			movegear(0,d*-1);
		}
		if(gear[1][2]!=gear[2][6]){
			if(gear[2][2]!=gear[3][6]){
				movegear(1,d);
				movegear(2,d*-1);
				movegear(3,d);
			}
			else{
				movegear(1,d);
				movegear(2,d*-1);
			}
		}
		else{
			movegear(1,d);
		}
	}
	else if(g==2){
		if(gear[2][2]!=gear[3][6]){
			movegear(3,d*-1);
		}
		if(gear[2][6]!=gear[1][2]){
			if(gear[1][6]!=gear[0][2]){
				movegear(2,d);
				movegear(1,d*-1);
				movegear(0,d);
			}
			else{
				movegear(2,d);
				movegear(1,d*-1);
			}
		}
		else{
			movegear(2,d);
		}
	}
	else{
		if(gear[3][6]!=gear[2][2]){
			if(gear[2][6]!=gear[1][2]){
				if(gear[1][6]!=gear[0][2]){
					movegear(3,d);
					movegear(2,d*-1);
					movegear(1,d);
					movegear(0,d*-1);
				}
				else{
					movegear(3,d);
					movegear(2,d*-1);
					movegear(1,d);
				}
			}
			else{
				movegear(3,d);
				movegear(2,d*-1);
			}
		}
		else{
			movegear(3,d);
		}
	}
}
int main(void){
	for(int i=0;i<4;i++){
		cin>>gear[i];
	}
	int K;
	cin>>K;
	for(int i=0;i<K;i++){
		int tmpg, tmpd;
		cin>>tmpg>>tmpd;
		checkmove(tmpg-1,tmpd);
	}
	int answer=0;
	int index=1;
	for(int i=0;i<4;i++){
		if(gear[i][0]=='1'){
			answer=answer+index;
		}
		index=index*2;
	}
	cout<<answer;
	return 0;
}