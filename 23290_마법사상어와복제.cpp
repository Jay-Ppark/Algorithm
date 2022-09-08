#include<iostream>
#include<vector>
using namespace std;
vector<int> fishmap[4][4];
vector<int> copyfishmap[4][4];
int sharky,sharkx;
int dy[9]={0,0,-1,-1,-1,0,1,1,1};
int dx[9]={0,-1,-1,0,1,1,1,0,-1};
int smellmap[4][4];
int dir[3];
int tmpdir[3];
int maxcnt= -1;
int sy[5]={0,-1,0,1,0};
int sx[5]={0,0,-1,0,1};
void copyfish(vector<int> copyf[4][4],vector<int> orif[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            copyf[i][j]=orif[i][j];
        }
    }
}
int changed(int d){
    if(d==1){
        return 8;
    }
    else if(d==2){
        return 1;
    }
    else if(d==3){
        return 2;
    }
    else if(d==4){
        return 3;
    }
    else if(d==5){
        return 4;
    }
    else if(d==6){
        return 5;
    }
    else if(d==7){
        return 6;
    }
    else{
        return 7;
    }
}
void movefish(){
    vector<int> tmpfish[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int t=0;t<fishmap[i][j].size();t++){
                int y=i;
                int x=j;
                int tmpd=fishmap[i][j][t];
                bool check=false;
                for(int d=0;d<8;d++){
                    y=i+dy[tmpd];
                    x=j+dx[tmpd];
                    if(y>=0&&y<4&&x>=0&&x<4){
                        if(smellmap[y][x]==0){
                            if(y==sharky&&x==sharkx){

                            }
                            else{
                                check=true;
                                break;
                            }
                        }
                    }
                    tmpd=changed(tmpd);
                }
                if(check){
                    tmpfish[y][x].push_back(tmpd);
                }
                else{
                    tmpfish[i][j].push_back(fishmap[i][j][t]);
                }
            }
        }
    }
    copyfish(fishmap,tmpfish);
}
int calfish(){
    bool visited[4][4]={false,};
    int tmpy=sharky;
    int tmpx=sharkx;
    int result=0;
    for(int i=0;i<3;i++){
        tmpy=tmpy+sy[tmpdir[i]];
        tmpx=tmpx+sx[tmpdir[i]];
        if(tmpy<0||tmpy>=4||tmpx<0||tmpx>=4){
            return -1;
        }
        else{
            if(!visited[tmpy][tmpx]){
                visited[tmpy][tmpx]=true;
                result=result+fishmap[tmpy][tmpx].size();
            }
        }
    }
    return result;
}
void moveshark(int cnt){
    if(cnt==3){
        int tmpmax=calfish();
        if(tmpmax>maxcnt){
            maxcnt=tmpmax;
            for(int i=0;i<3;i++){
                dir[i]=tmpdir[i];
            }
        }
        return;
    }
    for(int i=1;i<=4;i++){
        tmpdir[cnt]=i;
        moveshark(cnt+1);
    }
}
void eatfish(int t){
    moveshark(0);
    for(int i=0;i<3;i++){
        sharky=sharky+sy[dir[i]];
        sharkx=sharkx+sx[dir[i]];
        if(!fishmap[sharky][sharkx].empty()){
            fishmap[sharky][sharkx].clear();
            smellmap[sharky][sharkx]=t;
        }
    }
}
void deletesmell(int t){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(t-smellmap[i][j]==2){
                smellmap[i][j]=0;
            }
        }
    }
}
void domagic(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int t=0;t<copyfishmap[i][j].size();t++){
                fishmap[i][j].push_back(copyfishmap[i][j][t]);
            }
        }
    }
}
int main(void){
    int fishnum, magicnum;
    cin>>fishnum>>magicnum;
    for(int i=0;i<fishnum;i++){
        int tmpy,tmpx,tmpd;
        cin>>tmpy>>tmpx>>tmpd;
        fishmap[tmpy-1][tmpx-1].push_back(tmpd);
    }
    cin>>sharky>>sharkx;
    sharky--;
    sharkx--;
    for(int i=1;i<=magicnum;i++){
        maxcnt=-1;
        copyfish(copyfishmap,fishmap);
        movefish();
        eatfish(i);
        deletesmell(i);
        domagic();
    }
    int result=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            result=result+fishmap[i][j].size();
        }
    }
    cout<<result;
    return 0;
}