#include <iostream>
using namespace std;

int main() {

	int v[1000];
	int s[1000];
	int maxLength = 0;
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	s[0] = 1;
	maxLength = 1;
	for (int i = 1; i <= n-1; i++) {
		int max = 0;
		for (int j = 0; j <= i - 1; j++) {
			if (v[j] < v[i]) {
				if (s[j] > max) {
					max = s[j];
				}
			}
		}
		s[i] = max+1;
		if (s[i] > maxLength) {
			maxLength = s[i];
		}
	}

	cout << maxLength;

	return 0;
}