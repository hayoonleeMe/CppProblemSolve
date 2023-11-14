#include <bits/stdc++.h>
using namespace std;

int N, M;
int ans;
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		dq.push_back(i);

	int m;
	while (M--)
	{
		cin >> m;

		// 1
		if (dq.front() == m)
		{
			dq.pop_front();
			continue;
		}

		auto it = find(dq.begin(), dq.end(), m);
		int op2 = it - dq.begin();
		int op3 = dq.size() - op2;

		// 2
		if (op2 <= op3)
		{
			ans += op2;
			for (int i = 0; i < op2; ++i)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		// 3
		else
		{
			ans += op3;
			for (int i = 0; i < op3; ++i)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}

		// 1
		dq.pop_front();
	}

	cout << ans;
}