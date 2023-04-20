#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(const pair<int,string>& a,const pair<int,string>& b){
    return a.first<b.first;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<pair<int,string>> v;
    for(int i=0;i<N;i++){
        int tmp;
        string s;
        cin>>tmp>>s;
        v.push_back({tmp,s});
    }
    stable_sort(v.begin(),v.end(),comp);
    for(int i=0;i<(int)v.size();i++){
        cout<<v[i].first<<' '<<v[i].second<<'\n';
    }
    return 0;
}