#include<iostream>
#include<unordered_map>
using namespace std;
int main(void){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int M;
        cin>>M;
        unordered_map<string,int> um;
        for(int j=0;j<M;j++){
            string tmp, style;
            cin>>tmp>>style;
            if(um.find(style)==um.end()){
                um[style]=1;
            }
            else{
                um[style]++;
            }
        }
        int ans=1;
        for(auto e:um){
            ans=ans*(e.second+1);
        }
        cout<<ans-1<<'\n';
    }
    return 0;
}