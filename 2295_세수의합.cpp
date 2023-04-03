#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
vector<int> two;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            two.push_back(v[i]+v[j]);
        }
    }
    sort(two.begin(),two.end());
    for(int i=N-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(binary_search(two.begin(),two.end(),v[i]-v[j])){
                cout<<v[i];
                return 0;
            }
        }
    }
    return 0;
}