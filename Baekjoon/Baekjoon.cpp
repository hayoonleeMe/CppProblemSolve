#include <bits/stdc++.h>
using namespace std;

int N, r, c;

void func(int i, int j, int n, int k)
{
	if (n == 1)
	{
		int nk = pow(2.0, n - 1) * pow(2.0, n - 1);
		if (i == r && j == c)
			cout << k + 0 * nk;
		else if (i == r && j + 1 == c)
			cout << k + 1 * nk;
		else if (i + 1 == r && j == c)
			cout << k + 2 * nk;
		else if (i + 1 == r && j + 1 == c)
			cout << k + 3 * nk;
		return;
	}

	int offset = pow(2.0, n - 1);
	int nk = pow(2.0, n - 1) * pow(2.0, n - 1);

	if (r < i + offset && c < j + offset)
		func(i, j, n - 1, k + 0 * nk);
	else if (r < i + offset && c >= j + offset)
		func(i, j + offset, n - 1, k + 1 * nk);
	else if (r >= i + offset && c < j + offset)
		func(i + offset, j, n - 1, k + 2 * nk);
	else if (r >= i + offset && c >= j + offset)
		func(i + offset, j + offset, n - 1, k + 3 * nk);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> r >> c;
	func(0, 0, N, 0);
}