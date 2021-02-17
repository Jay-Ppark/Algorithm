#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string color = "wyrogb";
int N;
char cube[6][3][3];
char copyc[3][3];
string flip;
void clockwise(int num) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			copyc[i][j] = cube[num][i][j];
		}
	}
	//À­ ¿­
	for (int i = 0; i < 3; i++) {
		cube[num][0][i] = copyc[2 - i][0];
	}
	//Áß°£ ¿­
	cube[num][1][0] = copyc[2][1];
	cube[num][1][2] = copyc[0][1];
	//¾Æ·§ ¿­
	for (int i = 0; i < 3; i++) {
		cube[num][2][i] = copyc[2 - i][2];
	}
}
void counterclockwise(int num) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			copyc[i][j] = cube[num][i][j];
		}
	}
	//À­ ¿­
	for (int i = 0; i < 3; i++) {
		cube[num][0][i] = copyc[i][2];
	}
	//Áß°£ ¿­
	cube[num][1][0] = copyc[0][1];
	cube[num][1][2] = copyc[2][1];
	//¾Æ·§ ¿­
	for (int i = 0; i < 3; i++) {
		cube[num][2][i] = copyc[i][0];
	}
}
void U(int n) {
	char tmp[3];
	for (int i = 0; i < 3; i++) {
		tmp[i] = cube[4][n][i];
	}
	for (int i = 0; i < 3; i++) {
		cube[4][n][i] = cube[2][n][i];
	}
	for (int i = 0; i < 3; i++) {
		cube[2][n][i] = cube[5][n][i];
	}
	for (int i = 0; i < 3; i++) {
		cube[5][n][i] = cube[3][n][i];
	}
	for (int i = 0; i < 3; i++) {
		cube[3][n][i] = tmp[i];
	}
}
void D(int n) {
	char tmp[3];
	for (int i = 0; i < 3; i++) {
		tmp[i] = cube[4][n][i];
	}
	for (int i = 0; i < 3; i++) {
		cube[4][n][i] = cube[3][n][i];
	}
	for (int i = 0; i < 3; i++) {
		cube[3][n][i] = cube[5][n][i];
	}
	for (int i = 0; i < 3; i++) {
		cube[5][n][i] = cube[2][n][i];
	}
	for (int i = 0; i < 3; i++) {
		cube[2][n][i] = tmp[i];
	}
}
void L(int n) {
	int j = n == 0 ? 2 : 0;
	char tmp[3];
	for (int i = 0; i < 3; i++) {
		tmp[i] = cube[0][i][n];
	}
	for (int i = 0; i < 3; i++) {
		cube[0][i][n] = cube[3][2 - i][j];
	}
	for (int i = 0; i < 3; i++) {
		cube[3][i][j] = cube[1][2 - i][n];
	}
	for (int i = 0; i < 3; i++) {
		cube[1][i][n] = cube[2][i][n];
	}
	for (int i = 0; i < 3; i++) {
		cube[2][i][n] = tmp[i];
	}
}
void R(int n) {
	int j = n == 0 ? 2 : 0;
	char tmp[3];
	for (int i = 0; i < 3; i++) {
		tmp[i] = cube[0][i][n];
	}
	for (int i = 0; i < 3; i++) {
		cube[0][i][n] = cube[2][i][n];
	}
	for (int i = 0; i < 3; i++) {
		cube[2][i][n] = cube[1][i][n];
	}
	for (int i = 0; i < 3; i++) {
		cube[1][i][n] = cube[3][2 - i][j];
	}
	for (int i = 0; i < 3; i++) {
		cube[3][i][j] = tmp[2 - i];
	}
}
void F(int n) {
	int j = n == 0 ? 2 : 0;
	char tmp[3];
	for (int i = 0; i < 3; i++) {
		tmp[i] = cube[0][n][i];
	}
	for (int i = 0; i < 3; i++) {
		cube[0][n][i] = cube[4][2 - i][n];
	}
	for (int i = 0; i < 3; i++) {
		cube[4][i][n] = cube[1][j][i];
	}
	for (int i = 0; i < 3; i++) {
		cube[1][j][i] = cube[5][2 - i][j];
	}
	for (int i = 0; i < 3; i++) {
		cube[5][i][j] = tmp[i];
	}
}
void B(int n) {
	int j = n == 0 ? 2 : 0;
	char tmp[3];
	for (int i = 0; i < 3; i++) {
		tmp[i] = cube[0][n][i];
	}
	for (int i = 0; i < 3; i++) {
		cube[0][n][i] = cube[5][i][j];
	}
	for (int i = 0; i < 3; i++) {
		cube[5][i][j] = cube[1][j][2 - i];
	}
	for (int i = 0; i < 3; i++) {
		cube[1][j][i] = cube[4][i][n];
	}
	for (int i = 0; i < 3; i++) {
		cube[4][i][n] = tmp[2 - i];
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase > 0) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					cube[i][j][k] = color[i];
				}
			}
		}
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> flip;
			switch (flip[0]) {
			case 'U':
				if (flip[1] == '+') {
					clockwise(0);
					U(0);
				}
				else {
					counterclockwise(0);
					D(0);
				}
				break;
			case 'D':
				if (flip[1] == '+') {
					clockwise(1);
					D(2);
				}
				else {
					counterclockwise(1);
					U(2);
				}
				break;
			case 'F': 
				if (flip[1] == '+') {
					clockwise(2);
					F(2);
				}
				else {
					counterclockwise(2);
					B(2);
				}
				break;
			case 'B': 
				if (flip[1] == '+') {
					clockwise(3);
					B(0);
				}
				else {
					counterclockwise(3);
					F(0);
				}
				break;
			case 'L': 
				if (flip[1] == '+') {
					clockwise(4);
					L(0);
				}
				else {
					counterclockwise(4);
					R(0);
				}
				break;
			case 'R': 
				if (flip[1] == '+') {
					clockwise(5);
					R(2);
				}
				else {
					counterclockwise(5);
					L(2);
				}
				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[0][i][j];
			}
			cout << '\n';
		}
		testcase--;
	}
	return 0;
}