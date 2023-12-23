﻿#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1, 0, -1 };
int N, ans = 0x7f7f7f7f;
int board[105][105];
int dist[105][105];
queue<pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];

	int c = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (dist[i][j] == 1 || board[i][j] == 0)
				continue;

			dist[i][j] = 1;
			board[i][j] = c;
			q.push({ i, j });

			while (!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
						continue;
					if (dist[nx][ny] == 1 || board[nx][ny] == 0)
						continue;

					dist[nx][ny] = 1;
					board[nx][ny] = c;
					q.push({ nx, ny });
				}
			}
			++c;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] == 0)
				continue;

			for (int k = 0; k < N; ++k)
				fill(dist[k], dist[k] + N, -1);

			dist[i][j] = 0;
			q.push({ i, j });
			int cn = board[i][j];

			while (!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
						continue;
					if (board[nx][ny] == cn || dist[nx][ny] != -1)
						continue;

					if (board[nx][ny] != 0)
					{
						ans = min(ans, dist[cur.X][cur.Y]);
					}
					else
					{
						dist[nx][ny] = dist[cur.X][cur.Y] + 1;
						q.push({ nx, ny });
					}
				}
			}
			
		}
	}

	cout << ans;
}