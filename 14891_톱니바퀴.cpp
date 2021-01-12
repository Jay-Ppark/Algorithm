#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string gear[4];
int gindex[4];
void keepmove(int g, int d) {
	if (g == 0) {
		if (d == 1) {
			if (gear[0][(gindex[0] + 2) % 8] != gear[1][(gindex[1] + 6) % 8]) {
				if (gear[1][(gindex[1] + 2) % 8] != gear[2][(gindex[2] + 6) % 8]) {
					if (gear[2][(gindex[2] + 2) % 8] != gear[3][(gindex[3] + 6) % 8]) {
						gindex[0] = (gindex[0] + 7) % 8;
						gindex[1] = (gindex[1] + 1) % 8;
						gindex[2] = (gindex[2] + 7) % 8;
						gindex[3] = (gindex[3] + 1) % 8;
					}
					else {
						gindex[0] = (gindex[0] + 7) % 8;
						gindex[1] = (gindex[1] + 1) % 8;
						gindex[2] = (gindex[2] + 7) % 8;
					}
				}
				else {
					gindex[0] = (gindex[0] + 7) % 8;
					gindex[1] = (gindex[1] + 1) % 8;
				}
			}
			else {
				gindex[0] = (gindex[0] + 7) % 8;
			}
		}
		else {
			if (gear[0][(gindex[0] + 2) % 8] != gear[1][(gindex[1] + 6) % 8]) {
				if (gear[1][(gindex[1] + 2) % 8] != gear[2][(gindex[2] + 6) % 8]) {
					if (gear[2][(gindex[2] + 2) % 8] != gear[3][(gindex[3] + 6) % 8]) {
						gindex[0] = (gindex[0] + 1) % 8;
						gindex[1] = (gindex[1] + 7) % 8;
						gindex[2] = (gindex[2] + 1) % 8;
						gindex[3] = (gindex[3] + 7) % 8;
					}
					else {
						gindex[0] = (gindex[0] + 1) % 8;
						gindex[1] = (gindex[1] + 7) % 8;
						gindex[2] = (gindex[2] + 1) % 8;
					}
				}
				else {
					gindex[0] = (gindex[0] + 1) % 8;
					gindex[1] = (gindex[1] + 7) % 8;
				}
			}
			else {
				gindex[0] = (gindex[0] + 1) % 8;
			}
		}
	}
	else if (g == 1) {
		if (d == 1) {
			if (gear[0][(gindex[0] + 2) % 8] != gear[1][(gindex[1] + 6) % 8]) {
				if (gear[1][(gindex[1] + 2) % 8] != gear[2][(gindex[2] + 6) % 8]) {
					if (gear[2][(gindex[2] + 2) % 8] != gear[3][(gindex[3] + 6) % 8]) {
						gindex[0] = (gindex[0] + 1) % 8;
						gindex[1] = (gindex[1] + 7) % 8;
						gindex[2] = (gindex[2] + 1) % 8;
						gindex[3] = (gindex[3] + 7) % 8;
					}
					else {
						gindex[0] = (gindex[0] + 1) % 8;
						gindex[1] = (gindex[1] + 7) % 8;
						gindex[2] = (gindex[2] + 1) % 8;
					}
				}
				else {
					gindex[0] = (gindex[0] + 1) % 8;
					gindex[1] = (gindex[1] + 7) % 8;
				}
			}
			else {
				if (gear[1][(gindex[1] + 2) % 8] != gear[2][(gindex[2] + 6) % 8]) {
					if (gear[2][(gindex[2] + 2) % 8] != gear[3][(gindex[3] + 6) % 8]) {
						gindex[1] = (gindex[1] + 7) % 8;
						gindex[2] = (gindex[2] + 1) % 8;
						gindex[3] = (gindex[3] + 7) % 8;
					}
					else {
						gindex[1] = (gindex[1] + 7) % 8;
						gindex[2] = (gindex[2] + 1) % 8;
					}
				}
				else {
					gindex[1] = (gindex[1] + 7) % 8;
				}
			}
		}
		else {
			if (gear[0][(gindex[0] + 2) % 8] != gear[1][(gindex[1] + 6) % 8]) {
				if (gear[1][(gindex[1] + 2) % 8] != gear[2][(gindex[2] + 6) % 8]) {
					if (gear[2][(gindex[2] + 2) % 8] != gear[3][(gindex[3] + 6) % 8]) {
						gindex[0] = (gindex[0] + 7) % 8;
						gindex[1] = (gindex[1] + 1) % 8;
						gindex[2] = (gindex[2] + 7) % 8;
						gindex[3] = (gindex[3] + 1) % 8;
					}
					else {
						gindex[0] = (gindex[0] + 7) % 8;
						gindex[1] = (gindex[1] + 1) % 8;
						gindex[2] = (gindex[2] + 7) % 8;
					}
				}
				else {
					gindex[0] = (gindex[0] + 7) % 8;
					gindex[1] = (gindex[1] + 1) % 8;
				}
			}
			else {
				if (gear[1][(gindex[1] + 2) % 8] != gear[2][(gindex[2] + 6) % 8]) {
					if (gear[2][(gindex[2] + 2) % 8] != gear[3][(gindex[3] + 6) % 8]) {
						gindex[1] = (gindex[1] + 1) % 8;
						gindex[2] = (gindex[2] + 7) % 8;
						gindex[3] = (gindex[3] + 1) % 8;
					}
					else {
						gindex[1] = (gindex[1] + 1) % 8;
						gindex[2] = (gindex[2] + 7) % 8;
					}
				}
				else {
					gindex[1] = (gindex[1] + 1) % 8;
				}
			}
		}
	}
	else if (g == 2) {
		if (d == 1) {
			if (gear[2][(gindex[2] + 2) % 8] != gear[3][(gindex[3] + 6) % 8]) {
				if (gear[2][(gindex[2] + 6) % 8] != gear[1][(gindex[1] + 2) % 8]) {
					if (gear[1][(gindex[1] + 6) % 8] != gear[0][(gindex[0] + 2) % 8]) {
						gindex[0] = (gindex[0] + 7) % 8;
						gindex[1] = (gindex[1] + 1) % 8;
						gindex[2] = (gindex[2] + 7) % 8;
						gindex[3] = (gindex[3] + 1) % 8;
					}
					else {
						gindex[1] = (gindex[1] + 1) % 8;
						gindex[2] = (gindex[2] + 7) % 8;
						gindex[3] = (gindex[3] + 1) % 8;
					}
				}
				else {
					gindex[2] = (gindex[2] + 7) % 8;
					gindex[3] = (gindex[3] + 1) % 8;
				}
			}
			else {
				if (gear[2][(gindex[2] + 6) % 8] != gear[1][(gindex[1] + 2) % 8]) {
					if (gear[1][(gindex[1] + 6) % 8] != gear[0][(gindex[0] + 2) % 8]) {
						gindex[0] = (gindex[0] + 7) % 8;
						gindex[1] = (gindex[1] + 1) % 8;
						gindex[2] = (gindex[2] + 7) % 8;
					}
					else {
						gindex[1] = (gindex[1] + 1) % 8;
						gindex[2] = (gindex[2] + 7) % 8;
					}
				}
				else {
					gindex[2] = (gindex[2] + 7) % 8;
				}
			}
		}
		else {
			if (gear[2][(gindex[2] + 2) % 8] != gear[3][(gindex[3] + 6) % 8]) {
				if (gear[2][(gindex[2] + 6) % 8] != gear[1][(gindex[1] + 2) % 8]) {
					if (gear[1][(gindex[1] + 6) % 8] != gear[0][(gindex[0] + 2) % 8]) {
						gindex[0] = (gindex[0] + 1) % 8;
						gindex[1] = (gindex[1] + 7) % 8;
						gindex[2] = (gindex[2] + 1) % 8;
						gindex[3] = (gindex[3] + 7) % 8;
					}
					else {
						gindex[1] = (gindex[1] + 7) % 8;
						gindex[2] = (gindex[2] + 1) % 8;
						gindex[3] = (gindex[3] + 7) % 8;
					}
				}
				else {
					gindex[2] = (gindex[2] + 1) % 8;
					gindex[3] = (gindex[3] + 7) % 8;
				}
			}
			else {
				if (gear[2][(gindex[2] + 6) % 8] != gear[1][(gindex[1] + 2) % 8]) {
					if (gear[1][(gindex[1] + 6) % 8] != gear[0][(gindex[0] + 2) % 8]) {
						gindex[0] = (gindex[0] + 1) % 8;
						gindex[1] = (gindex[1] + 7) % 8;
						gindex[2] = (gindex[2] + 1) % 8;
					}
					else {
						gindex[1] = (gindex[1] + 7) % 8;
						gindex[2] = (gindex[2] + 1) % 8;
					}
				}
				else {
					gindex[2] = (gindex[2] + 1) % 8;
				}
			}
		}
	}
	else {
		if (d == 1) {
			if (gear[3][(gindex[3] + 6) % 8] != gear[2][(gindex[2] + 2) % 8]) {
				if (gear[2][(gindex[2] + 6) % 8] != gear[1][(gindex[1] + 2) % 8]) {
					if (gear[1][(gindex[1] + 6) % 8] != gear[0][(gindex[0] + 2) % 8]) {
						gindex[0] = (gindex[0] + 1) % 8;
						gindex[1] = (gindex[1] + 7) % 8;
						gindex[2] = (gindex[2] + 1) % 8;
						gindex[3] = (gindex[3] + 7) % 8;
					}
					else {
						gindex[1] = (gindex[1] + 7) % 8;
						gindex[2] = (gindex[2] + 1) % 8;
						gindex[3] = (gindex[3] + 7) % 8;
					}
				}
				else {
					gindex[2] = (gindex[2] + 1) % 8;
					gindex[3] = (gindex[3] + 7) % 8;
				}
			}
			else {
				gindex[3] = (gindex[3] + 7) % 8;
			}
		}
		else {
			if (gear[3][(gindex[3] + 6) % 8] != gear[2][(gindex[2] + 2) % 8]) {
				if (gear[2][(gindex[2] + 6) % 8] != gear[1][(gindex[1] + 2) % 8]) {
					if (gear[1][(gindex[1] + 6) % 8] != gear[0][(gindex[0] + 2) % 8]) {
						gindex[0] = (gindex[0] + 7) % 8;
						gindex[1] = (gindex[1] + 1) % 8;
						gindex[2] = (gindex[2] + 7) % 8;
						gindex[3] = (gindex[3] + 1) % 8;
					}
					else {
						gindex[1] = (gindex[1] + 1) % 8;
						gindex[2] = (gindex[2] + 7) % 8;
						gindex[3] = (gindex[3] + 1) % 8;
					}
				}
				else {
					gindex[2] = (gindex[2] + 7) % 8;
					gindex[3] = (gindex[3] + 1) % 8;
				}
			}
			else {
				gindex[3] = (gindex[3] + 1) % 8;
			}
		}
	}
}
int main(void) {
	for (int i = 0; i < 4; i++) {
		cin >> gear[i];
	}
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int gearnum, dir;
		cin >> gearnum >> dir;
		keepmove(gearnum-1, dir);
	}
	int result = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i][gindex[i]] == '1') {
			result = result + (int)pow(2, i);
		}
	}
	cout << result;
	return 0;
}