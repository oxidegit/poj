#include <iostream>
using namespace std;

void output(int cube, int a, int b, int c) {
	cout << "Cube = " << cube << ", ";
	cout << "Triple = (" << a << "," << b << "," << c << ")";
}

int main() {
	int max = 0;
	cin >> max;
	int i = 2;
	int j = 3;
	int k = 4;
	int vi, vj, vk;
	int vm = max*max*max;

	for (int n = k + 1; n <= max; n++) {
		for (i = 2, vi = i*i*i; i <= max - 3; i++, vi = i*i*i) {
			for (j = i, vj = j*j*j; vm >= vi + vj; j++, vj = j*j*j) {
				for (k = j, vk = k*k*k; vm >= vi + vj + vk; k++, vk = k*k*k) {

					if ((n*n*n) == i*i*i + j*j*j + k*k*k) {
						output(n, i, j, k);
						cout << endl;
						break;
					}

				}
			}
		}
	}

		return 0;
	}