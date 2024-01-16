#include <bits/stdc++.h>
using namespace std;

string A, B;
int d[1002][1002];

void LCS(int i, int j)
{
	if (i <= 0 || j <= 0)
		return;

	if (A[i - 1] == B[j - 1])
	{
		LCS(i - 1, j - 1);
		cout << A[i - 1];
	}
	else
	{
		if (d[i - 1][j] > d[i][j - 1])
			LCS(i - 1, j);
		else
			LCS(i, j - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> A >> B;
	for (int i = 1; i <= A.size(); ++i)
	{
		for (int j = 1; j <= B.size(); ++j)
		{
			if (A[i - 1] == B[j - 1])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}

	cout << d[A.size()][B.size()] << '\n';

	if (d[A.size()][B.size()] > 0)
		LCS(A.size(), B.size());
}

//ACAYKP
//CAPCAK
//ACAK
//
//d[i][j] : 첫 문자열의 i번째까지 부분수열과 두번째 문자열의 j번째까지 부분수열에서 LCS 길이
//d[i][j] = (첫 문자열의 i번째 문자 == 두번째 문자열의 j번째 문자) d[i-1][j-1] + 1
//		  (다르면) max(d[i-1][j], d[i][j-1])
//
//d[1][1] = 0
//
//d[1][2] = d[0][1] + 1 = 1
//d[1][3] = max(d[1][2], d[0][3]) = 1
//d[1][4] = 1
//d[1][5] = 1
//d[1][6] = 1
//
//d[2][1] = d[1][0] + 1 = 1
//d[2][2] = max(d[2][1], d[1][2]) =1
//d[2][3] = 1
//d[2][4] = d[1][3] + 1 = 2
//d[2][5] = 2
//d[2][6] = 2
//
//d[3][1] = 1
//d[3][2] = d[2][1] + 1 = 2
//...