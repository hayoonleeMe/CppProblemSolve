#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
vector<int> a[1002];
int d[1002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> A >> B;
		a[B].push_back(A);
	}

	for (int i = 1; i <= N; ++i)
	{
		for (const int pre : a[i])
			d[i] = max(d[i], d[pre]);
		d[i] += 1;
	}

	for (int i = 1; i <= N; ++i)
		cout << d[i] << ' ';
}

//6 4
//1 2
//1 3
//2 5
//4 5
//
//d[i] : i번 과목을 이수할 수 있는 최소 학기
//d[1] = 1
//d[2] = 1 + d[1] = 2
//d[3] = 1 + d[1] = 2
//d[4] = 1
//d[5] = 1 + max(d[2], d[4]) = 3
//d[6] = 1