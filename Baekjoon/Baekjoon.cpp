#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool mask[25];
string board[5];
int ans;
queue<pair<int, int>> q;

// next_permutation 사용
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < 5; ++i)
		cin >> board[i];

	fill(mask + 7, mask + 25, true);

	do
	{
		bool seq[5][5] = {}, visited[5][5] = {};
		for (int i = 0; i < 25; ++i)
		{
			if (!mask[i])
			{
				int x = i / 5, y = i % 5;
				seq[x][y] = 1;

				if (q.empty())
				{
					visited[x][y] = 1;
					q.push({ x, y });
				}
			}
		}

		int ns = 0, adj = 0;
		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front();
			q.pop();

			++adj;
			ns += (board[x][y] == 'S');

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
					continue;
				if (visited[nx][ny] == 1 || seq[nx][ny] == 0)
					continue;

				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}

		ans += (adj >= 7 && ns >= 4);
			
	} while (next_permutation(mask, mask + 25));

	cout << ans;
}