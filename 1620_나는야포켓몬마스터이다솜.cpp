#include<iostream>
#include<unordered_map>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string,int> m;
    unordered_map<int,string> um;
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        m[tmp]=i+1;
        um[i+1]=tmp;
    }
    for(int i=0;i<M;i++){
        string tmp;
        cin>>tmp;
        if(tmp[0]-'A'>=0||tmp[0]-'a'>=0){
            cout<<m[tmp]<<'\n';
        }
        else{
            int a=stoi(tmp);
            cout<<um[a]<<'\n';
        }
    }
    return 0;
}