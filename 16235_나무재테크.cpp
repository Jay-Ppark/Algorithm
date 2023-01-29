#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,K;
int ground[10][10];
int initground[10][10];
int tmpground[10][10];
vector<int> tree[10][10];
int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={-1,0,1,-1,1,-1,0,1};
int treecnt;
void spring(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sort(tree[i][j].begin(),tree[i][j].end());
            for(int t=0;t<tree[i][j].size();t++){
                if(ground[i][j]>=tree[i][j][t]){
                    ground[i][j]=ground[i][j]-tree[i][j][t];
                    tree[i][j][t]++;
                }
                else{
                    for(int r=tree[i][j].size()-1;r>=t;r--){
                        tmpground[i][j]=tmpground[i][j]+(tree[i][j][r]/2);
                        tree[i][j].pop_back();
                        treecnt--;
                    }
                }
            }
        }
    }
}
void summer(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ground[i][j]=ground[i][j]+tmpground[i][j];
            tmpground[i][j]=0;
        }
    }
}
void fall(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int t=0;t<tree[i][j].size();t++){
                if(tree[i][j][t]%5==0){
                    for(int d=0;d<8;d++){
                        int ny=i+dy[d];
                        int nx=j+dx[d];
                        if(ny>=0&&ny<N&&nx>=0&&nx<N){
                            tree[ny][nx].push_back(1);
                            treecnt++;
                        }
                    }
                }
            }
        }
    }
}
void winter(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ground[i][j]=ground[i][j]+initground[i][j];
        }
    }
}
int main(void){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>initground[i][j];
            ground[i][j]=5;
        }
    }
    for(int i=0;i<M;i++){
        int x,y,z;
        cin>>y>>x>>z;
        tree[y-1][x-1].push_back(z);
        treecnt++;
    }
    for(int t=0;t<K;t++){
        spring();
        summer();
        fall();
        winter();
    }
    cout<<treecnt;
    return 0;
}