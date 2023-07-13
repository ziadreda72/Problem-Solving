#include <bits/stdc++.h>

using namespace std;

int32_t main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cout.tie(nullptr);cout.precision(20);
	string s , t;
	cin >> s >> t;
	int n = (int) s.size() , m = (int) t.size();
	vector < int > cnt(26 , 0) , cntQ(n + 1 , 0);
	vector < vector < int > > pref(26 , vector < int > (n + 1 , 0));
	s = '!' + s;
	for (int i = 0; i < 26; ++i) {
		for (int j = 1; j <= n; ++j) {
			pref[i][j] += pref[i][j - 1] + (s[j] == char('a' + i));
		}
	}
	for (int i = 1; i <= n; ++i) {
		cntQ[i] += cntQ[i - 1] + (s[i] == '?');
	}
	for (int i = 0; i < m; ++i) {
		cnt[t[i] - 'a']++;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if(i + m - 1 > n)
			break;
		int q = 0;
		bool ok = 1;
		for (int j = 0; j < 26; ++j) {
			if(cnt[j] < pref[j][i + m - 1] - pref[j][i - 1]){
				ok = 0;
				break;
			}
			q += cnt[j] - pref[j][i + m - 1] - pref[j][i - 1];
		}
		if(cntQ[i + m - 1] - cntQ[i - 1] < q)
			ok = 0;
		ans += ok;
	}
	cout << ans;
	return 0;
}
