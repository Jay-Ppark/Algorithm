#include<iostream>
using namespace std;
int arr[20][20];
int width, height;
int starty, startx;
int cmdnum;
int dice[4][3];
int tmpdice[4][3];
int garoindex = 1;
int seroindex = 1;
void initdice() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			tmpdice[i][j] = dice[i][j];
		}
	}
}
int playdice(int dir) {
	//right
	if (dir == 1) {
		startx++;
		if (startx >= width) {
			startx--;
			return -1;
		}
		initdice();
		dice[1][1] = tmpdice[1][0];
		dice[3][1] = tmpdice[1][2];
		dice[1][0] = tmpdice[3][1];
		dice[1][2] = tmpdice[1][1];
		if (arr[starty][startx] == 0) {
			arr[starty][startx] = dice[3][1];
		}
		else {
			dice[3][1] = arr[starty][startx];
			arr[starty][startx] = 0;
		}
		return dice[1][1];
	}
	//left
	else if (dir == 2) {
		startx--;
		if (startx < 0) {
			startx++;
			return -1;
		}
		initdice();
		dice[1][1] = tmpdice[1][2];
		dice[3][1] = tmpdice[1][0];
		dice[1][0] = tmpdice[1][1];
		dice[1][2] = tmpdice[3][1];
		if (arr[starty][startx] == 0) {
			arr[starty][startx] = dice[3][1];
		}
		else {
			dice[3][1] = arr[starty][startx];
			arr[starty][startx] = 0;
		}
		return dice[1][1];
	}
	//up
	else if (dir == 3) {
		starty--;
		if (starty < 0) {
			starty++;
			return -1;
		}
		initdice();
		for (int i = 0; i < 4; i++) {
			dice[i][1] = tmpdice[(i + 3) % 4][1];
		}
		if (arr[starty][startx] == 0) {
			arr[starty][startx] = dice[3][1];
		}
		else {
			dice[3][1] = arr[starty][startx];
			arr[starty][startx] = 0;
		}
		return dice[1][1];
	}
	//down
	else {
		starty++;
		if (starty >= height) {
			starty--;
			return -1;
		}
		initdice();
		for (int i = 0; i < 4; i++) {
			dice[i][1] = tmpdice[(i + 1) % 4][1];
		}
		if (arr[starty][startx] == 0) {
			arr[starty][startx] = dice[3][1];
		}
		else {
			dice[3][1] = arr[starty][startx];
			arr[starty][startx] = 0;
		}
		return dice[1][1];
	}
}
int main(void) {
	cin >> height >> width >> starty >> startx >> cmdnum;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < cmdnum; i++) {
		int cmd;
		cin >> cmd;
		int result = playdice(cmd);
		if (result != -1) {
			cout << result << '\n';
		}
		/*
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				cout << dice[i][j] << " ";
			}
			cout << '\n';
		}
		*/
	}
	return 0;
}