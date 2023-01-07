#include<iostream>
using namespace std;
int blockmap[100][100];
int N,L;
bool garo(int y){
	int prev=blockmap[y][0];
	bool visited[N]={false,};
	for(int i=1;i<N;i++){
		//차가 1 초과인 경우
		if(abs(prev-blockmap[y][i])>1){
			return false;
		}
		else{
			if(abs(prev-blockmap[y][i])==1){
				if(prev<blockmap[y][i]){
					if(i-L>=0){
						for(int j=i-1;j>=i-L;j--){
							if(prev==blockmap[y][j]){
								if(!visited[j]){
									visited[j]=true;
								}
								else{
									return false;
								}
							}
							else{
								return false;
							}
						}
						prev=blockmap[y][i];
					}
					else{
						return false;
					}
				}
				else{
					if(i+L<=N){
						for(int j=i;j<i+L;j++){
							if(blockmap[y][i]==blockmap[y][j]){
								if(!visited[j]){
									visited[j]=true;
								}
								else{
									return false;
								}
							}
							else{
								return false;
							}
						}
						prev=blockmap[y][i+L-1];
						i=i+L-1;
					}
					else{
						return false;
					}
				}
			}
		}
	}
	return true;
}
bool sero(int x){
	int prev=blockmap[0][x];
	bool visited[N]={false,};
	for(int i=1;i<N;i++){
		//차가 1 초과인 경우
		if(abs(prev-blockmap[i][x])>1){
			return false;
		}
		else{
			if(abs(prev-blockmap[i][x])==1){
				if(prev<blockmap[i][x]){
					if(i-L>=0){
						for(int j=i-1;j>=i-L;j--){
							if(prev==blockmap[j][x]){
								if(!visited[j]){
									visited[j]=true;
								}
								else{
									return false;
								}
							}
							else{
								return false;
							}
						}
						prev=blockmap[i][x];
					}
					else{
						return false;
					}
				}
				else{
					if(i+L<=N){
						for(int j=i;j<i+L;j++){
							if(blockmap[i][x]==blockmap[j][x]){
								if(!visited[j]){
									visited[j]=true;
								}
								else{
									return false;
								}
							}
							else{
								return false;
							}
						}
						prev=blockmap[i+L-1][x];
						i=i+L-1;
					}
					else{
						return false;
					}
				}
			}
		}
	}
	return true;
}
int main(void){
	cin>>N>>L;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>blockmap[i][j];
		}
	}
	int cnt=0;
	for(int i=0;i<N;i++){
		if(garo(i)){
			cnt++;
		}
		if(sero(i)){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}