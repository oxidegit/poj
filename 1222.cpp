#include <memory>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

char oriLight[5];
char lights[5];
char result[5];

void setBit(char & c, int i, int a) {
	if (a) {
		c |= (1 << i);
	}
	else {
		c &= ~(1 << i);
	}
}

int getBit(char c, int i) {
	return (c >> i) & 1;
}

void filpBit(char &c, int i) {
	c ^= (1 << i);
}

void outputResult(int t, char result[]) {
	cout << "PUZZLE #" << t << endl;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) {
			cout << getBit(result[i], j);
			if (j != 5)
				cout << " ";
		}
		cout << endl;
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 6; ++j) {
				int a;
				cin >> a;
				setBit(oriLight[i], j, a);
			}
		}

		for (int n = 0; n < 64; ++n) {
			memcpy(lights, oriLight, sizeof(oriLight));
			int switchs = n;
			for (int i = 0; i < 5; ++i) {
				result[i] = switchs;

				for (int j = 0; j < 6; j++) {
					if (getBit(result[i], j)) {
						if (j > 0)
							filpBit(lights[i], j-1);
						filpBit(lights[i], j);
						if (j < 5)
							filpBit(lights[i], j + 1);
					}	
				}
				if (i < 4)
					lights[i + 1] ^= switchs;
				switchs = lights[i];


			}
			if (lights[4] == 0) {
				outputResult(t, result);
				break;
			}
			
		}
		
	}

	return 0;
}