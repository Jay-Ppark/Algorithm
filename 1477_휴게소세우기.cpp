#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
bool comp(int a,int b){
	if(a<b){
		return true;
	}
	else{
		return false;
	}
}
int main(void){
	int N,M,L;
	cin>>N>>M>>L;
	v.push_back(0);
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	v.push_back(L);
	sort(v.begin(),v.end(),comp);
	int left=1;
	int right=L;
	int mid=0;
	int result=0;
	while(left<=right){
		int val=0;
		mid = (right+left)/2;
		//cout<<"left"<<left<<",right"<<right<<",mid"<<mid<<'\n';
		for(int i=1;i<v.size();i++){
			int d = v[i]-v[i-1];
			val=val+(d/mid);
			if(d%mid==0){
				val--;
			}
		}
		if(val>M){
			left=mid+1;
		}
		else{
			right=mid-1;
			result=mid;
			//cout<<result<<'\n';
		}
	}
	cout<<result;
	return 0;
}