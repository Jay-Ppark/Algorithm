#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int N;
int C;
int findmaxlen(){
	int left=0;
	int right=1000000000;
	while(left<=right){
		int tmpcnt=1;
		int mid=(left+right)/2;
		int prev=v[0];
		for(int i=1;i<v.size();i++){
			if(v[i]-prev>=mid){
				prev=v[i];
				tmpcnt++;
			}
		}
		if(tmpcnt>=C){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	return right;
}
int main(void){
	cin>>N>>C;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	cout<<findmaxlen();
	return 0;
}