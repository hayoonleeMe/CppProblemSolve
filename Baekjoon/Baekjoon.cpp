#include <bits/stdc++.h>
using namespace std;

int N;
char board[2200][2200];

void func(int n, int i, int j)
{
	if (n == 1)
	{
		board[i][j] = '*';
		return;
	}

	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			if (r == 1 && c == 1)
				continue;
			func(n / 3, i + n / 3 * r, j + n / 3 * c);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		fill(board[i], board[i] + N, ' ');

	func(N, 0, 0);

	for (int i = 0; i < N; ++i)
		cout << board[i] << '\n';
}