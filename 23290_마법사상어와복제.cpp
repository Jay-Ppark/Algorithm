#include<iostream>
#include<vector>
using namespace std;
struct fish{
    int y;
    int x;
    int d;
};
int sharky,sharkx;
vector<fish> fishmap[4][4];
vector<fish> copyfishmap[4][4];
int smellmap[4][4];
int tmproute[3];
int route[3];
int sy[5]={0,-1,0,1,0};
int sx[5]={0,0,-1,0,1};
int fy[9]={0,0,-1,-1,-1,0,1,1,1};
int fx[9]={0,-1,-1,0,1,1,1,0,-1};
int eatfishmax=-1;
void copyfish(vector<fish> needcopy[4][4],vector<fish> original[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            needcopy[i][j]=original[i][j];
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
    vector<fish> tmpfishmap[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<fishmap[i][j].size();k++){
                bool check=false;
                int y=i;
                int x=j;
                int d=fishmap[i][j][k].d;
                int ny = y;
                int nx = x;
                for(int t=0;t<8;t++){
                    ny=y+fy[d];
                    nx=x+fx[d];
                    if(ny>=0&&ny<4&&nx>=0&&nx<4){
                        if((ny==sharky&&nx==sharkx)||smellmap[ny][nx]!=0){
                            d=changed(d);
                        }
                        else{
                            check=true;
                            break;
                        }
                    }
                    else{
                        d=changed(d);
                    }
                }
                if(check){
                    tmpfishmap[ny][nx].push_back({ny,nx,d});
                }
                else{
                    tmpfishmap[y][x].push_back({y,x,d});
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            fishmap[i][j]=tmpfishmap[i][j];
        }
    }
}
int calfish(){
    bool visited[4][4]={false,};
    int tmpsy=sharky;
    int tmpsx=sharkx;
    int result=0;
    for(int i=0;i<3;i++){
        tmpsy=tmpsy+sy[tmproute[i]];
        tmpsx=tmpsx+sx[tmproute[i]];
        if(tmpsy<0||tmpsy>=4||tmpsx<0||tmpsx>=4){
            return -1;
        }
        else{
            if(!visited[tmpsy][tmpsx]){
                visited[tmpsy][tmpsx]=true;
                result=result+fishmap[tmpsy][tmpsx].size();
            }
        }
    }
    return result;
}
void findroute(int cnt){
    if(cnt==3){
        int tmpmax=calfish();
        if(tmpmax>eatfishmax){
            eatfishmax=tmpmax;
            for(int i=0;i<3;i++){
                route[i]=tmproute[i];
            }
        }
        return;
    }
    for(int i=1;i<=4;i++){
        tmproute[cnt]=i;
        findroute(cnt+1);
    }
}
void moveshark(int t){
    findroute(0);
    for(int i=0;i<3;i++){
        sharky=sharky+sy[route[i]];
        sharkx=sharkx+sx[route[i]];
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
            for(int k=0;k<copyfishmap[i][j].size();k++){
                fishmap[i][j].push_back(copyfishmap[i][j][k]);
            }
        }
    }
}
void init(){
    for(int i=0;i<3;i++){
        tmproute[i]=0;
    }
}
int main(void){
    int fishnum;
    int magicnum;
    cin>>fishnum>>magicnum;
    for(int i=0;i<fishnum;i++){
        int y,x,d;
        cin>>y>>x>>d;
        fish f={y-1,x-1,d};
        fishmap[y-1][x-1].push_back(f);
    }
    cin>>sharky>>sharkx;
    sharky--;
    sharkx--;
    for(int i=1;i<=magicnum;i++){
        copyfish(copyfishmap,fishmap);
        eatfishmax=-1;
        init();
        movefish();
        moveshark(i);
        deletesmell(i);
        domagic();
    }
    int answer=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            answer=answer+fishmap[i][j].size();
        }
    }
    cout<<answer;
    return 0;
}