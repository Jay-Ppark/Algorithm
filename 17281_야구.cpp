#include<iostream>
#include<vector>
using namespace std;
int inningN;
int playerScore[50][9];
bool selected[9];
bool ground[3];
int score;
vector<int> player;
void Init(){
	for(int i=0;i<3;i++){
		ground[i]=false;
	}
}
void play(){
	int outcnt = 0;
	int tmpscore = 0;
	int tmpinning = 0;
	int number=0;
	while(tmpinning<inningN){
		if(outcnt==3){
			outcnt=0;
			tmpinning++;
			Init();
			if(tmpinning==inningN){
				break;
			}
		}
		if(number==9){
			number = number - 9;
		}
		if(playerScore[tmpinning][player[number]]==0){
			outcnt++;
		}
		else if(playerScore[tmpinning][player[number]]==1){
			if(ground[2]){
				tmpscore++;
				ground[2]=false;
			}
			if(ground[1]){
				ground[2]=true;
				ground[1]=false;
			}
			if(ground[0]){
				ground[0]=false;
				ground[1]=true;
			}
			ground[0]=true;
		}
		else if(playerScore[tmpinning][player[number]]==2){
			if(ground[2]){
				tmpscore++;
				ground[2]=false;
			}
			if(ground[1]){
				tmpscore++;
				ground[1]=false;
			}
			if(ground[0]){
				ground[2]=true;
				ground[0]=false;
			}
			ground[1]=true;
		}
		else if(playerScore[tmpinning][player[number]]==3){
			if(ground[2]){
				tmpscore++;
				ground[2]=false;
			}
			if(ground[1]){
				tmpscore++;
				ground[1]=false;
			}
			if(ground[0]){
				tmpscore++;
				ground[0]=false;
			}
			ground[2]=true;
		}
		else{
			for(int j=0;j<3;j++){
				if(ground[j]){
					tmpscore++;
					ground[j]=false;
				}
			}
			tmpscore++;
		}
		number++;
	}
	if(tmpscore>score){
		score=tmpscore;
	}
}
void selectPlayer(){
	if(player.size()==8){
		player.insert(player.begin() + 3, 0);
		play();
		player.erase(player.begin()+3);
		return;
	}
	for(int i=1;i<9;i++){
		if(!selected[i]){
			selected[i]=true;
			player.push_back(i);
			selectPlayer();
			player.pop_back();
			selected[i]=false;
		}
	}
}
int main(void){
	cin>>inningN;
	for(int i=0;i<inningN;i++){
		for(int j=0;j<9;j++){
			cin>>playerScore[i][j];
		}
	}
	selectPlayer();
	cout<<score;
	return 0;
}