#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> v[1001];
int visiteda[1001];
int visitedb[1001];
int citynum, roadnum;
void Init(){
    for(int i=0;i<=1000;i++){
        visiteda[i]=0;
        visitedb[i]=0;
        if(!v[i].empty()){
            v[i].clear();
        }
    }
}
int BFS(int a,int b){
    queue<int> aq;
    queue<int> bq;
    visiteda[a]=1;
    visitedb[b]=1;
    aq.push(a);
    bq.push(b);
    int saven=0;
    int anum=1;
    int bnum=1;
    int turns=1;
    while(!aq.empty() && !bq.empty()){
        int tmpas = aq.size();
        for(int j=0;j<tmpas;j++){
            int tmpa = aq.front();
            aq.pop();
            for(int i=0;i<v[tmpa].size();i++){
                if(visiteda[v[tmpa][i]]==0){
                    aq.push(v[tmpa][i]);
                    visiteda[v[tmpa][i]]=turns;
                    anum++;
                    }
                }
            }
        int tmpbs = bq.size();
        for(int j=0;j<tmpbs;j++){
            int tmpb = bq.front();
            bq.pop();
            for(int i=0;i<v[tmpb].size();i++){
                if(visitedb[v[tmpb][i]]==turns){
                    visitedb[v[tmpb][i]]=turns;
                    anum--;
                    saven++;
                }
                else if(visitedb[v[tmpb][i]]==0 && visiteda[v[tmpb][i]]!=0){
                    bq.push(v[tmpb][i]);
                    bnum++;
                }
            }
        }
        turns++;
        cout<<anum<<" "<<bnum<<" "<<turns<<'\n'; 
    }
    int nonum = citynum-anum-bnum-saven;
    if(anum>bnum){
        return saven, 0;
    }
    else if(anum+nonum+saven<=bnum){
        return saven, -1;
    }
    else{
        return saven, bnum+1-anum;
    }
}
int main() {
    int testcase;
    cin >> testcase;
    int cnt=1;
    while(testcase>0){
        cin>>citynum>>roadnum;
        int astart, bstart;
        cin>>astart>>bstart;
        int startn, endn;
        for(int i=0;i<roadnum;i++){
            cin>>startn>>endn;
            v[startn].push_back(endn);
            v[endn].push_back(startn);
        }
        int s, result = BFS(astart,bstart);
        cout<<"#"<<cnt<<" "<<s<<" "<<result<<'\n';
        Init();
        testcase--;
        cnt++;
    }
    return 0;
}