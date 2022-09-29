#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int h,w;
int needtemp;
int tempmap[20][20];
bool wallmap[20][20][4];
vector<pair<pair<int,int>,int>> heater;
vector<pair<int,int>> checkzone;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int wy[4][3]={{-1,0,1},{1,1,1},{-1,0,1},{-1,-1,-1}};
int wx[4][3]={{1,1,1},{-1,0,1},{-1,-1,-1},{-1,0,1}};
bool checkwall(int y,int x,int ny,int nx,int d,int i){
    if(d==0){
        if(i==0){
            if(!wallmap[y][x][3]&&!wallmap[ny][nx][2]){
                return true; 
            }
        }
        else if(i==1){
            if(!wallmap[y][x][0]){
                return true;
            }
        }
        else{
            if(!wallmap[y][x][1]&&!wallmap[ny][nx][2]){
                return true;
            }
        }
    }
    else if(d==1){
        if(i==0){
            if(!wallmap[y][x][1]&&!wallmap[ny][nx][0]){
                return true;
            }
        }
        else if(i==1){
            if(!wallmap[y][x][1]){
                return true;
            }
        }
        else{
            if(!wallmap[y][x]&&!wallmap[ny][nx][2]){
                return true;
            }
        }
    }
    else if(d==2){
        if(i==0){
            if(!wallmap[y][x][2]&&!wallmap[ny][nx][1]){
                return true;
            }
        }
        else if(i==1){
            if(!wallmap[y][x][2]){
                return true;
            }
        }
        else{
            if(!wallmap[y][x][2]&&!wallmap[ny][nx][3]){
                return true;
            }
        }
    }
    else{
        if(i==0){
            if(!wallmap[y][x][3]&&!wallmap[ny][nx][0]){
                return true;
            }
        }
        else if(i==1){
            if(!wallmap[y][x][3]){
                return true;
            }
        }
        else{
            if(!wallmap[y][x][3]&&!wallmap[ny][nx][2]){
                return true;
            }
        }
    }
    return false;
}
void spreadwind(int y,int x,int d){
    bool visited[20][20]={false,};
    int ny=y+dy[d];
    int nx=x+dx[d];
    if(ny<0||ny>=h||nx<0||nx>=w){
        return;
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{ny,nx},5});
    while(!q.empty()){
        int y=q.front().first.first;
        int x=q.front().first.second;
        int heat=q.front().second;
        q.pop();
        tempmap[y][x]=tempmap[y][x]+heat;
        if(heat==1){
            continue;
        }
        for(int i=0;i<3;i++){
            int ny=y+wy[d][i];
            int nx=x+wx[d][i];
            if(ny>=0&&ny<h&&nx>=0&&nx<w){
                if(visited[ny][nx]==false&&checkwall(y,x,ny,nx,d,i)==true){
                    q.push({{ny,nx},heat-1});
                    visited[ny][nx]=true;
                }
            }
        }
    }
}
void doheat(){
    for(int i=0;i<heater.size();i++){
        int y=heater[i].first.first;
        int x=heater[i].first.second;
        int d=heater[i].second;
        spreadwind(y,x,d);
    }
}
void adjusttemp(){
    int tmpheat[20][20]={0,};
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i==h-1&&j==w-1){
                continue;
            }
            else if(i==h-1&&!wallmap[i][j][0]){
                int a=tempmap[i][j];
                int b=tempmap[i][j+1];
                if(a>=b){
                    int diff=(a-b)/4;
                    tmpheat[i][j]=tmpheat[i][j]-diff;
                    tmpheat[i][j+1]=tmpheat[i][j+1]+diff;
                }
                else{
                    int diff=(b-a)/4;
                    tmpheat[i][j]=tmpheat[i][j]+diff;
                    tmpheat[i][j+1]=tmpheat[i][j+1]-diff;
                }
            }
            else if(j==w-1&&!wallmap[i][j][1]){
                int a=tempmap[i][j];
                int b=tempmap[i+1][j];
                if(a>=b){
                    int diff=(a-b)/4;
                    tmpheat[i][j]=tmpheat[i][j]-diff;
                    tmpheat[i+1][j]=tmpheat[i+1][j]+diff;
                }
                else{
                    int diff=(b-a)/4;
                    tmpheat[i][j]=tmpheat[i][j]+diff;
                    tmpheat[i+1][j]=tmpheat[i+1][j]-diff;
                }
            }
            else{
                int a=tempmap[i][j];
                int b=tempmap[i][j+1];
                int c=tempmap[i+1][j];
                if(!wallmap[i][j][0]){
                    if(a>=b){
                        int diff=(a-b)/4;
                        tmpheat[i][j]=tmpheat[i][j]-diff;
                        tmpheat[i][j+1]=tmpheat[i][j+1]+diff;
                    }
                    else{
                        int diff=(b-a)/4;
                        tmpheat[i][j]=tmpheat[i][j]+diff;
                        tmpheat[i][j+1]=tmpheat[i][j+1]-diff;
                    }
                }
                if(!wallmap[i][j][1]){
                    if(a>=c){
                        int diff=(a-c)/4;
                        tmpheat[i][j]=tmpheat[i][j]-diff;
                        tmpheat[i+1][j]=tmpheat[i+1][j]+diff;
                    }
                    else{
                        int diff=(c-a)/4;
                        tmpheat[i][j]=tmpheat[i][j]+diff;
                        tmpheat[i+1][j]=tmpheat[i+1][j]-diff;
                    }
                }
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            tempmap[i][j]=tempmap[i][j]+tmpheat[i][j];
        }
    }
}
void decreasetemp(){
    for(int i=0;i<w;i++){
        if(tempmap[0][i]>=1){
            tempmap[0][i]--;
        }
        if(tempmap[h-1][i]>=1){
            tempmap[h-1][i]--;
        }
    }
    for(int i=0;i<h;i++){
        if(tempmap[i][0]>=1){
            tempmap[i][0]--;
        }
        if(tempmap[i][w-1]>=1){
            tempmap[i][w-1]--;
        }
    }
}
bool checktemp(){
    for(int i=0;i<checkzone.size();i++){
        if(tempmap[checkzone[i].first][checkzone[i].second]<needtemp){
            return false;
        }
    }
    return true;
}
int main(void){
    cin>>h>>w>>needtemp;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>tempmap[i][j];
            if(tempmap[i][j]!=0){
                if(tempmap[i][j]==5){
                    checkzone.push_back({i,j});
                }
                else{
                    if(tempmap[i][j]==1){
                        heater.push_back({{i,j},0});
                    }
                    else if(tempmap[i][j]==2){
                        heater.push_back({{i,j},2});
                    }
                    else if(tempmap[i][j]==3){
                        heater.push_back({{i,j},3});
                    }
                    else{
                        heater.push_back({{i,j},1});
                    }
                }
            }
        }
    }
    int wallnum;
    cin>>wallnum;
    for(int i=0;i<wallnum;i++){
        int tmpy,tmpx,dir;
        cin>>tmpy>>tmpx>>dir;
        if(dir==0){
            wallmap[tmpy-2][tmpx-1][1]=true;
            wallmap[tmpy-1][tmpx-1][3]=true;
        }
        else{
            wallmap[tmpy-1][tmpx][2]=true;
            wallmap[tmpy-1][tmpx-1][0]=true;
        }
    }
    int chocolate=0;
    while(true){
        if(chocolate>100){
            break;
        }
        doheat();
        adjusttemp();
        decreasetemp();
        chocolate++;
        if(checktemp()){
            break;
        }
    }
    cout<<chocolate;
    return 0;
}