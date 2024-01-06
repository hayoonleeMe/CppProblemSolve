#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;
string board[52];
int vis[52][52];
queue<pair<int, int>> q;
const int MAX = 0x7f7f7f7f;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		fill(vis[i], vis[i] + N, MAX);
		cin >> board[i];
	}

	vis[0][0] = 0;
	q.push({ 0, 0 });

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

			int nVis = vis[cur.X][cur.Y];
			if (board[nx][ny] == '0')
				++nVis;

			if (nVis < vis[nx][ny])
			{
				vis[nx][ny] = nVis;
				q.push({ nx, ny });
			}
		}
	}

	cout << vis[N - 1][N - 1];
}

// 처음에 벽을 깬 횟수를 저장하는 것까지는 생각했는데,
// 횟수를 저장하는 초기 값을 전부다 0으로 설정해서 더이상 나아가지 못하는 부분에서 막혔다.
// 여기서 초기 값을 큰 값으로 설정해야 가능했다.
// 어떤 방에 도착하면 이전에 도착했을 때보다 더 적은 횟수로 부쉈을 때 갱신
//
