#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int N,M,K;
vector<int> gun[20][20];
tuple<int,int,int,int,int> human[31];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
void dogame(){
    for(int i=1;i<=M;i++){
        
    }
}
int main(void){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int tmp;
            if(tmp>0){
                gun[i][j].push_back(tmp);
            }
        }
    }
    for(int i=1;i<=M;i++){
        int y,x,d,s;
        cin>>y>>x>>d>>s;
        human[i]=make_tuple(y-1,x-1,d,s,0);
    }
    while(K>0){
        dogame();
        K--;
    }
    return 0;
}