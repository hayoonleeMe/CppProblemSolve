#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
string board[1005];
int dist[1005][1005];
// x, y, 벽 부순 횟수
queue<tuple<int, int, int>> q;
queue<tuple<int, int, int>> wq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
		fill(dist[i], dist[i] + M, -1);
	}

	dist[0][0] = 1;
	q.push({ 0, 0, 0 });

	while (!q.empty())
	{
		int x, y, cnt;
		tie(x, y, cnt) = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (dist[nx][ny] != -1)
				continue;

			if (board[nx][ny] == '0')
			{
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx, ny, cnt });
			}
			else if (board[nx][ny] == '1')
			{
				dist[nx][ny] = dist[x][y] + 1;
				wq.push({ nx, ny, cnt + 1 });
			}
		}
	}

	while (!wq.empty())
	{
		int x, y, cnt;
		tie(x, y, cnt) = wq.front();
		wq.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (board[nx][ny] == '0')
			{
				if (dist[nx][ny] == -1 || dist[x][y] + 1 < dist[nx][ny])
				{
					dist[nx][ny] = dist[x][y] + 1;
					wq.push({ nx, ny, cnt });
				}
			}
		}
	}

	cout << dist[N - 1][M - 1];
}