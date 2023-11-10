#include <bits/stdc++.h>
using namespace std;

int N, X;
int seq[100000];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> seq[i];
	cin >> X;

	sort(seq, seq + N);

	int count = 0, left = 0, right = N - 1;
	while (left < right)
	{
		int sum = seq[left] + seq[right];
		if (sum == X)
		{
			++count;
			++left;
			--right;
		}
		else if (sum > X)
			--right;
		else if (sum < X)
			++left;
	}

	cout << count;
}