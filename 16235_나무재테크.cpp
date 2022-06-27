#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int treenum;
int years;
vector<int> tree[10][10];
int winternut[10][10];
int nut[10][10];
int dead[10][10];
int dy[8]={-1,-1,-1,0,1,1,1,0};
int dx[8]={-1,0,1,1,1,0,-1,-1};
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            nut[i][j]=5;
        }
    }
}
bool comp(int a,int b){
    if(a<b){
        return true;
    }
    else{
        return false;
    }
}
void spring(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!tree[i][j].empty()){
                sort(tree[i][j].begin(),tree[i][j].end(),comp);
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<tree[i][j].size();k++){
                if(tree[i][j][k]<=nut[i][j]){
                    nut[i][j]=nut[i][j]-tree[i][j][k];
                    tree[i][j][k]++;
                }
                else{
                    int treesize=tree[i][j].size()-1;
                    for(int p=treesize;p>=k;p--){
                        dead[i][j]=dead[i][j]+(tree[i][j][p]/2);
                        tree[i][j].pop_back();
                        treenum--;
                    }
                }
            }
        }
    }
}
void summer(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(dead[i][j]>0){
                nut[i][j]=nut[i][j]+dead[i][j];
                dead[i][j]=0;
            }
        }
    }
}
void fall(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<tree[i][j].size();k++){
                if(tree[i][j][k]%5==0){
                    for(int p=0;p<8;p++){
                        int ny=i+dy[p];
                        int nx=j+dx[p];
                        if(ny>=0&&ny<N&&nx>=0&&nx<N){
                            tree[ny][nx].push_back(1);
                            treenum++;
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
            nut[i][j]=nut[i][j]+winternut[i][j];
        }
    }
}
int main(void){
    cin>>N>>treenum>>years;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>winternut[i][j];
        }
    }
    for(int i=0;i<treenum;i++){
        int x,y,z;
        cin>>y>>x>>z;
        tree[y-1][x-1].push_back(z);
    }
    init();
    for(int i=0;i<years;i++){
        spring();
        summer();
        fall();
        winter();
        if(treenum==0){
            break;
        }
    }
    cout<<treenum;
    return 0;
}