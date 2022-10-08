#include<iostream>
#include<vector>
using namespace std;
int N;
int studentmap[21][21];
vector<int> friendv[401];
int friendorder[401];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};
int studenty,studentx;
void countzone(int index){
	int maxstudentcnt=-1;
	int maxvacant=-1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(studentmap[i][j]==0){
				int studentcnt=0;
				int vacantcnt=0;
				for(int d=0;d<4;d++){
					int ny=i+dy[d];
					int nx=j+dx[d];
					if(ny>=1&&ny<=N&&nx>=1&&nx<=N){
						if(studentmap[ny][nx]==0){
							vacantcnt++;
						}
						else{
							for(int k=0;k<4;k++){
								if(studentmap[ny][nx]==friendv[friendorder[index]][k]){
									studentcnt++;
									break;				
								}
							}
						}	
					}
				}
				if(maxstudentcnt<studentcnt){
					maxstudentcnt=studentcnt;
					maxvacant=vacantcnt;
					studenty=i;
					studentx=j;
				}
				else if(maxstudentcnt==studentcnt){
					if(maxvacant<vacantcnt){
						maxvacant=vacantcnt;
						studenty=i;
						studentx=j;
					}
				}
			}
		}
	}
}
void matchzone(){
	for(int i=1;i<=N*N;i++){
		if(i==1){
			studentmap[2][2]=friendorder[i];
		}
		else{
			countzone(i);
			studentmap[studenty][studentx]=friendorder[i];
		}
	}
}
int countscore(){
	int score=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			int stustand=studentmap[i][j];
			int cnt=0;
			for(int d=0;d<4;d++){
				int ny=i+dy[d];
				int nx=j+dx[d];
				if(ny>=1&&ny<=N&&nx>=1&&nx<=N){
					for(int k=0;k<4;k++){
						if(friendv[stustand][k]==studentmap[ny][nx]){
							cnt++;
							break;
						}
					}
				}
			}
			if(cnt==2){
				score=score+10;
			}
			else if(cnt==3){
				score=score+100;
			}
			else if(cnt==4){
				score=score+1000;
			}
			else{
				score=score+cnt;
			}
		}
	}
	return score;
}
int main(void){
	cin>>N;
	for(int i=1;i<=N*N;i++){
		int fnum;
		cin>>fnum;
		friendorder[i]=fnum;
		for(int j=0;j<4;j++){
			int tmp;
			cin>>tmp;
			friendv[fnum].push_back(tmp);
		}
	}
	matchzone();
	cout<<countscore();
	return 0;
}