#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
vector<int> v;
vector<int> vv;
int cnt[8001]; // -4000~4000
int main(void){
    int N;
    cin>>N;
    double sum=0;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        sum+=tmp;
        v.push_back(tmp);
        cnt[tmp+4000]++;
    }
    sort(v.begin(),v.end());
    //평균
    if(round(sum/N)==-0){
        cout<<0<<'\n';
    }
    else{
        cout<<round(sum/N)<<'\n';
    }
    //중앙값
    cout<<v[N/2]<<'\n';
    //최빈값
    int tmpmin=0;
    for(int i=0;i<=8000;i++){
        if(tmpmin<cnt[i]){
            tmpmin=cnt[i];
        }
    }
    for(int i=0;i<=8000;i++){
        if(tmpmin==cnt[i]){
            vv.push_back(i-4000);
        }
    }
    if(vv.size()>1){
        cout<<vv[1]<<'\n';
    }
    else{
        cout<<vv[0]<<'\n';
    }
    //범위
    cout<<v.back()-v.front();
    return 0;
}