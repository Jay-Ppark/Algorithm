#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
int M,T;
int py,px;
vector<int> gamemap[4][4];
vector<int> copymap[4][4];
int deadmap[4][4];
int tmpdir[3];
int dir[3];
int my[8]={-1,-1,0,1,1,1,0,-1};
int mx[8]={0,-1,-1,-1,0,1,1,1};
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
int maxeat=-1;
void copymonster(){
    //몬스터 복제
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            copymap[i][j]=gamemap[i][j];
        }
    }
}
void movemonster(){
    //임시변수
    vector<int> tmpmap[4][4];
    //몬스터 이동
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(!gamemap[i][j].empty()){
                for(int k=0;k<(int)gamemap[i][j].size();k++){
                    int d=gamemap[i][j][k];
                    bool cango=false;
                    //8가지 방향 모두 확인
                    for(int c=0;c<8;c++){
                        int ny=i+my[d];
                        int nx=j+mx[d];
                        //범위 확인
                        if(ny>=0&&ny<4&&nx>=0&&nx<4){
                            //팩맨이 없고
                            if(ny==py&&nx==px){
                    
                            }
                            else{
                                //시체가 없고
                                if(deadmap[ny][nx]==0){
                                    tmpmap[ny][nx].push_back(d);
                                    cango=true;
                                    break;
                                }
                            }
                        }
                        d++;
                        d%=8;
                    }
                    //갈 수 없는 경우
                    if(!cango){
                        tmpmap[i][j].push_back(d);
                    }
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            gamemap[i][j].clear();
            gamemap[i][j]=tmpmap[i][j];
        }
    }
}
int caleat(){
    bool visited[4][4]={false,};
    int result=0;
    int ty=py;
    int tx=px;
    for(int i=0;i<3;i++){
        ty+=dy[tmpdir[i]];
        tx+=dx[tmpdir[i]];
        if(ty>=0&&ty<4&&tx>=0&&tx<4){
            if(!visited[ty][tx]){
                result+=gamemap[ty][tx].size();
                visited[ty][tx]=true;
            }
        }
        else{
            return -1;
        }
    }
    return result;
}
void movepack(int cnt){
    if(cnt==3){
        int tmpmax=caleat();
        if(tmpmax==-1){
            return;
        }
        if(tmpmax>maxeat){
            maxeat=tmpmax;
            for(int i=0;i<3;i++){
                dir[i]=tmpdir[i];
            }
        }
        return;
    }
    for(int i=0;i<4;i++){
        tmpdir[cnt]=i;
        movepack(cnt+1);
    }
}
void eatmonster(int c){
    for(int i=0;i<3;i++){
        py+=dy[dir[i]];
        px+=dx[dir[i]];
        if(!gamemap[py][px].empty()){
            deadmap[py][px]=c;
            gamemap[py][px].clear();
        }
    }
}
void deletedead(int c){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(c-deadmap[i][j]==2){
                deadmap[i][j]=0;
            }
        }
    }
}
void finishcopy(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<(int)copymap[i][j].size();k++){
                gamemap[i][j].push_back(copymap[i][j][k]);
            }
            copymap[i][j].clear();
        }
    }
}
int main(void){
    cin>>M>>T;
    cin>>py>>px;
    py--;
    px--;
    for(int i=0;i<M;i++){
        int y,x,d;
        cin>>y>>x>>d;
        gamemap[y-1][x-1].push_back(d-1);
    }
    int round=1;
    while(round<=T){
        maxeat=-1;
        //몬스터 복제
        copymonster();
        //몬스터 이동
        movemonster();
        //팩맨 이동
        movepack(0);
        //팩맨 먹기
        eatmonster(round);
        //시체 지우기
        deletedead(round);
        //복제 완성
        finishcopy();
        round++;
    }
    int answer=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            answer+=gamemap[i][j].size();
        }
    }
    cout<<answer;
    return 0;
}