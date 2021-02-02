#include<iostream>
#include<vector>
using namespace std;
int N;
int maxchicken;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int minchickendis = 1000000;
bool visitedchicken[13];
void erasechicken(int cnt,int nextc) {
	if (cnt == maxchicken) {
		int chickendissum = 0;
		for (int i = 0; i < house.size(); i++) {
			int mindis = 1000000;
			int tmpdis = 0;
			for (int j = 0; j < chicken.size(); j++) {
				if (visitedchicken[j]) {
					tmpdis = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
					if (tmpdis < mindis) {
						mindis = tmpdis;
					}
				}
			}
			chickendissum = chickendissum + mindis;
		}
		if (minchickendis > chickendissum) {
			minchickendis = chickendissum;
		}
		return;
	}
	for (int i = nextc; i < chicken.size(); i++) {
		if (!visitedchicken[i]) {
			visitedchicken[i] = true;
			erasechicken(cnt + 1, i + 1);
			visitedchicken[i] = false;
		}
	}
}
int main(void) {
	cin >> N >> maxchicken;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) {
				house.push_back({ i,j });
			}
			else if (tmp == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	erasechicken(0, 0);
	cout << minchickendis;
	return 0;
}