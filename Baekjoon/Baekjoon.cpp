#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int seq[10];
bool isused[10];

void func(int cur)
{
	if (cur == M)
	{
		for (int i = 0; i < M; ++i)
			cout << seq[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (isused[i])
			continue;
		if (cur > 0 && seq[cur - 1] > arr[i])
			continue;

		seq[cur] = arr[i];
		isused[i] = 1;
		func(cur + 1);
		isused[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);

	func(0);
}