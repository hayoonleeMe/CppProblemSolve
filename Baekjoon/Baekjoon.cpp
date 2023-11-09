#include <bits/stdc++.h>
using namespace std;

// 전역에 배열을 선언하면 0으로 초기화됨
int alpha[26];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	/*int alpha[26];
	int alpha[26] = {};
	fill(alpha, alpha + 26, 0);
	memset(alpha, 0, sizeof(alpha));*/

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); ++i)
		++alpha[int(s[i] - 'a')];

	for (int i = 0; i < 26; ++i)
		cout << alpha[i] << ' ';
}