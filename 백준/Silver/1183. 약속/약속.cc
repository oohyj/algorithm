#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back(a - b);
	}
	sort(v.begin(), v.end());

	if (n % 2 == 1) cout << 1;
	else cout << v[n / 2] - v[n / 2 - 1] + 1;

	return 0;
}