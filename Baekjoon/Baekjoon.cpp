#include <bits/stdc++.h>
using namespace std;

int N;
int a, b, c;
int dmax[2][3];
int dmin[2][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b >> c;

		dmax[1][0] = a + max(dmax[0][0], dmax[0][1]);
		dmax[1][1] = b + max({ dmax[0][0], dmax[0][1], dmax[0][2] });
		dmax[1][2] = c + max(dmax[0][1], dmax[0][2]);

		dmax[0][0] = dmax[1][0];
		dmax[0][1] = dmax[1][1];
		dmax[0][2] = dmax[1][2];

		dmin[1][0] = a + min(dmin[0][0], dmin[0][1]);
		dmin[1][1] = b + min({ dmin[0][0], dmin[0][1], dmin[0][2] });
		dmin[1][2] = c + min(dmin[0][1], dmin[0][2]);

		dmin[0][0] = dmin[1][0];
		dmin[0][1] = dmin[1][1];
		dmin[0][2] = dmin[1][2];
	}

	cout << max({ dmax[0][0], dmax[0][1], dmax[0][2] }) << ' ' << min({ dmin[0][0], dmin[0][1], dmin[0][2] });
}

//3
//1 2 3
//4 5 6
//4 9 0
//
//최대
//dmax[i][j] : i행 j열에서 얻을 수 있는 최대 점수
//d[0][0] = 1
//d[0][1] = 2
//d[0][2] = 3
//
//d[1][0] = a[1][0] + max(d[0][0], d[0][1])
//d[1][1] = a[1][1] + max(d[0][0], d[0][1], d[0][2])
//d[1][2] = a[1][2] + max(d[0][1], d[0][2])
//
//최소
//dmin[i][j] : i행 j열에서 얻을 수 있는 최소 점수
//
//d[1][0] = a[1][0] + min(d[0][0], d[0][1])
//d[1][1] = a[1][1] + min(d[0][0], d[0][1], d[0][2])
//d[1][2] = a[1][2] + min(d[0][1], d[0][2])