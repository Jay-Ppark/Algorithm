#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
vector<int> arr;
int main(void){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<N;i++){
        cout<<lower_bound(v.begin(),v.end(),arr[i])-v.begin()<<' ';
    }
    return 0;
}