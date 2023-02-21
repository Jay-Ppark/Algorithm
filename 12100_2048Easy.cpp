#include<iostream>
#include<vector>
using namespace std;
int N;
int gamemap[20][20];
int tmpgamemap[20][20];
vector<int> dir;
int maxgame=0;
void moveleft(){
    int tmp[20];
    for(int i=0;i<N;i++){
        fill(tmp,tmp+20,0);
        int index=0;
        for(int j=0;j<N;j++){
            if(tmpgamemap[i][j]==0){
                continue;
            }
            if(tmp[index]==0){
                tmp[index]=tmpgamemap[i][j];
            }
            else if(tmp[index]==tmpgamemap[i][j]){
                tmp[index]=tmp[index]*2;
                index++;
            }
            else{
                index++;
                tmp[index]=tmpgamemap[i][j];
            }
        }
        for(int j=0;j<N;j++){
            tmpgamemap[i][j]=tmp[j];
        }
    }
}
void moveright(){
    int tmp[20];
    for(int i=0;i<N;i++){
        fill(tmp,tmp+20,0);
        int index=N-1;
        for(int j=N-1;j>=0;j--){
            if(tmpgamemap[i][j]==0){
                continue;
            }
            if(tmp[index]==0){
                tmp[index]=tmpgamemap[i][j];
            }
            else if(tmp[index]==tmpgamemap[i][j]){
                tmp[index]=tmp[index]*2;
                index--;
            }
            else{
                index--;
                tmp[index]=tmpgamemap[i][j];
            }
        }
        for(int j=0;j<N;j++){
            tmpgamemap[i][j]=tmp[j];
        }
    }
}
void moveup(){
    int tmp[20];
    for(int i=0;i<N;i++){
        fill(tmp,tmp+20,0);
        int index=0;
        for(int j=0;j<N;j++){
            if(tmpgamemap[j][i]==0){
                continue;
            }
            if(tmp[index]==0){
                tmp[index]=tmpgamemap[j][i];
            }
            else if(tmp[index]==tmpgamemap[j][i]){
                tmp[index]=tmp[index]*2;
                index++;
            }
            else{
                index++;
                tmp[index]=tmpgamemap[j][i];
            }
        }
        for(int j=0;j<N;j++){
            tmpgamemap[j][i]=tmp[j];
        }
    }
}
void movedown(){
    int tmp[20];
    for(int i=0;i<N;i++){
        fill(tmp,tmp+20,0);
        int index=N-1;
        for(int j=N-1;j>=0;j--){
            if(tmpgamemap[j][i]==0){
                continue;
            }
            if(tmp[index]==0){
                tmp[index]=tmpgamemap[j][i];
            }
            else if(tmp[index]==tmpgamemap[j][i]){
                tmp[index]=tmp[index]*2;
                index--;
            }
            else{
                index--;
                tmp[index]=tmpgamemap[j][i];
            }
        }
        for(int j=0;j<N;j++){
            tmpgamemap[j][i]=tmp[j];
        }
    }
}
int calgame(){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            tmpgamemap[i][j]=gamemap[i][j];
        }
    }
    for(int i=0;i<5;i++){
        if(dir[i]==0){
            moveleft();
        }
        else if(dir[i]==1){
            moveright();
        }
        else if(dir[i]==2){
            moveup();
        }
        else{
            movedown();
        }
    }
    int maxnum=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(tmpgamemap[i][j]>maxnum){
                maxnum=tmpgamemap[i][j];
            }
        }
    }
    return maxnum;
}
void selectd(int cnt){
    if(cnt==5){
        int tmpmax=calgame();
        if(tmpmax>maxgame){
            maxgame=tmpmax;
        }
        return;
    }
    for(int i=0;i<4;i++){
        dir.push_back(i);
        selectd(cnt+1);
        dir.pop_back();
    }
}
int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>gamemap[i][j];
        }
    }
    selectd(0);
    cout<<maxgame;
    return 0;
}