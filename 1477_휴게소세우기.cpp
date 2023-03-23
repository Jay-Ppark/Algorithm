#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,maxL;
vector<int> v;
bool visited[1001];
bool comp(int &a,int &b){
	if(a<b){
		return true;
	}
	else{
		return false;
	}
}
int main(void){
	cin>>N>>M>>maxL;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	v.push_back(0);
	v.push_back(maxL);
	sort(v.begin(),v.end(),comp);
	int left=1;
	int right=maxL;
	int mid=0;
	int result=0;
	while(left<=right){
		mid=(left+right)/2;
		int add=0;
		for(int i=1;i<v.size();i++){
			int d= v[i]-v[i-1];
			add=add+d/mid;
			if(d%mid==0){
				add--;
			}
		}
		if(add>M){
			left=mid+1;
		}
		else{
			right=mid-1;
			result=mid;
		}
	}
	cout<<result;
	return 0;
}