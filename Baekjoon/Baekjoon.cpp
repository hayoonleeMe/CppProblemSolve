#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int N, M;
string board[100];
int visited[100][100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
int dist[100][100];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int n = 0; n < N; ++n)
		cin >> board[n];

	visited[0][0] = 1;
	q.push({ 0,0 });
	dist[0][0] = 1;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		if (cur.X == N - 1 && cur.Y == M - 1)
			break;

		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] != '1')
				continue;

			if (!visited[nx][ny] || dist[cur.X][cur.Y] + 1 < dist[nx][ny])
			{
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			}
		}
	}

	cout << dist[N - 1][M - 1];
}