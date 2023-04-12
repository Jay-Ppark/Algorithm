#include<iostream>
#include<deque>
using namespace std;
int arr[5000001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,L;
    cin>>N>>L;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    deque<pair<int,int>> dq;
    for(int i=1;i<=N;i++){
        if(!dq.empty()){
            if(dq.front().second<i-L+1){
                dq.pop_front();
            }
        }
        while(!dq.empty()&&dq.back().first>arr[i]){
            dq.pop_back();
        }
        dq.push_back({arr[i],i});
        cout<<dq.front().first<<' ';
    }
    return 0;
}