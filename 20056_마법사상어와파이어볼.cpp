#include<iostream>
#include<vector>
using namespace std;
int N, firenum, ordernum;
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,1,1,1,0,-1,-1,-1};
vector<pair<pair<int,int>,int>> fire[51][51];
void movefire(){
    vector<pair<pair<int,int>,int>> tmpfire[51][51];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=0;k<fire[i][j].size();k++){
                int tmpw=fire[i][j][k].first.first;
                int tmps=fire[i][j][k].first.second;
                int tmpd=fire[i][j][k].second;
                int ny=i;
                int nx=j;
                for(int s=0;s<tmps;s++){
                    ny=ny+dy[tmpd];
                    nx=nx+dx[tmpd];
                    if(ny==0){
                        ny=N;
                    }
                    else if(ny>N){
                        ny=1;
                    }
                    if(nx==0){
                        nx=N;
                    }
                    else if(nx>N){
                        nx=1;
                    }
                }
                tmpfire[ny][nx].push_back({{tmpw,tmps},tmpd});
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            fire[i][j].clear();
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(tmpfire[i][j].size()>=2){
                int sumw=tmpfire[i][j][0].first.first;
                int checkd=tmpfire[i][j][0].second%2;
                int sums=tmpfire[i][j][0].first.second;
                bool issame=true;
                for(int k=1;k<tmpfire[i][j].size();k++){
                    sumw=sumw+tmpfire[i][j][k].first.first;
                    int tmpd=tmpfire[i][j][k].second;
                    sums=sums+tmpfire[i][j][k].first.second;
                    if((tmpd%2)!=checkd){
                        issame=false;
                    }
                }
                int tmpw=sumw/5;
                int tmps=sums/tmpfire[i][j].size();
                if(tmpw!=0){
                    if(issame){
                        for(int d=0;d<8;d++){
                            if(d%2==0){
                                fire[i][j].push_back({{tmpw,tmps},d});
                            }
                        }
                    }
                    else{
                        for(int d=0;d<8;d++){
                            if(d%2==1){
                                fire[i][j].push_back({{tmpw,tmps},d});
                            }
                        }
                    }
                }
            }
            else{
                for(int k=0;k<tmpfire[i][j].size();k++){
                    int tmpw=tmpfire[i][j][k].first.first;
                    int tmps=tmpfire[i][j][k].first.second;
                    int tmpd=tmpfire[i][j][k].second;
                    fire[i][j].push_back({{tmpw,tmps},tmpd});
                }
            }
        }
    }
}
int calfire(){
    int answ=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=0;k<fire[i][j].size();k++){
                answ=answ+fire[i][j][k].first.first;
            }
        }
    }
    return answ;
}
int main(void){
    cin>>N>>firenum>>ordernum;
    for(int i=0;i<firenum;i++){
        int tmpy,tmpx,tmpw,tmps,tmpd;
        cin>>tmpy>>tmpx>>tmpw>>tmps>>tmpd;
        fire[tmpy][tmpx].push_back({{tmpw,tmps},tmpd});
    }
    for(int i=0;i<ordernum;i++){
        movefire();
    }
    cout<<calfire()<<'\n';
    return 0;
}