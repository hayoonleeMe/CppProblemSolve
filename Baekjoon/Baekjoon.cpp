#include <bits/stdc++.h>
using namespace std;

int N; 
vector<long long> v;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		// 변환한 값이 정수 범위를 초과 한다면 std::out_or_range 를 던진다.
		v.push_back(stoll(s));
	}

	sort(v.begin(), v.end());
	for (long long n : v)
		cout << n << '\n';
}