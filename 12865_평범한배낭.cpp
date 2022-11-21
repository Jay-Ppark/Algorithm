#include<iostream>
#include<vector>
using namespace std;
int N, maxweight;
vector<pair<int,int>> item;
int dp[101][100001];
int main(void){
    cin>>N>>maxweight;
    item.push_back({0,0});
    for(int i=0;i<N;i++){
        int tmpw,tmpv;
        cin>>tmpw>>tmpv;
        item.push_back({tmpw,tmpv});
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=maxweight;j++){
            if(j-item[i].first>=0){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-item[i].first]+item[i].second);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[N][maxweight];
    return 0;
}