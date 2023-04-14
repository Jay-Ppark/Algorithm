#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
	int N,K;
	cin>>N>>K;
	vector<pair<int,int>> v;
	multiset<int> bag;
	for(int i=0;i<N;i++){
		int w,p;
		cin>>w>>p;
		v.push_back({p,w});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<K;i++){
		int tmp;
		cin>>tmp;
		bag.insert(tmp);
	}
	long long int ans=0;
	for(int i=N-1;i>=0;i--){
		int w,p;
		p=v[i].first;
		w=v[i].second;
		auto it=bag.lower_bound(w);
		if(it==bag.end()){
			continue;
		}
		ans+=p;
		bag.erase(it);
	}
	cout<<ans;
	return 0;
}