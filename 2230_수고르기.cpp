#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main(void){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int minM=2000000000;
    sort(v.begin(),v.end());
    int st=0;
    int en=0;
    while(st<v.size()){
        for(int i=en;i<(int)v.size();i++){
            if(v[i]-v[st]>=M){
                //cout<<st<<i<<'\n';
                if(v[i]-v[st]<minM){
                    //cout<<minM<<'\n';
                    minM=v[i]-v[st];
                }
                en=i;
                break;
            }
        }
        st++;
    }
    cout<<minM;
    return 0;
}