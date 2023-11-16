#include <bits/stdc++.h>
using namespace std;

int N, K;
int dist[100001];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	memset(dist, -1, sizeof(dist));

	dist[N] = 0;
	q.push(N);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nx : { cur - 1, cur + 1, 2 * cur })
		{
			// K가 100,000까지라고 제한도 반드시 100,000까지일 필요는 없음 (2배씩 갈 수 있으므로)
			// 그러나 이 문제에서는 100,000으로 제한해도 괜찮다. 하지만 다른 문제에서는 주의
			if (nx < 0 || nx > 100000)
				continue;
			if (dist[nx] != -1)
				continue;
			
			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}

	cout << dist[K];
}