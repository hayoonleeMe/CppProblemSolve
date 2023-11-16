#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int R, C;
string board[1000];
int fire[1000][1000];
int dist[1000][1000];
queue<pair<int, int>> F;
queue<pair<int, int>> J;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		fill(fire[i], fire[i] + C, -1);
		fill(dist[i], dist[i] + C, -1);
		cin >> board[i];
	}

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (board[i][j] == 'F')
			{
				fire[i][j] = 0;
				F.push({ i, j });
			}
			else if (board[i][j] == 'J')
			{
				dist[i][j] = 0;
				J.push({ i, j });
			}
		}
	}

	while (!F.empty())
	{
		pair<int, int> cur = F.front();
		F.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (fire[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;

			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
			F.push({ nx, ny });
		}
	}

	while (!J.empty())
	{
		pair<int, int> cur = J.front();
		J.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				cout << dist[cur.X][cur.Y] + 1;
				return 0;
			}

			if (board[nx][ny] == '#' || dist[nx][ny] >= 0)
				continue;
			if (fire[nx][ny] != -1 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1)
				continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			J.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";
}