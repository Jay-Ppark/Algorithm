#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long int> v;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        long long int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int resultmax=0;
    long long int result=v[0];
    int tmpmax=1;
    long long int prev=v[0];
    for(int i=1;i<v.size();i++){
        if(prev==v[i]){
            tmpmax++;
        }
        else{
            if(tmpmax>resultmax){
                resultmax=tmpmax;
                result=prev;
            }
            prev=v[i];
            tmpmax=1;
        }
        if(i==N-1){
            if(tmpmax>resultmax){
                result=prev;
            }
        }
    }
    cout<<result;
    return 0;
}