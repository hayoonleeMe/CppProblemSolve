#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int arr[3];
	for (int i = 0; i < 3; ++i)
		cin >> arr[i];
	sort(arr, arr + 3);

	int c = 1;
	if (arr[1] == arr[0])
		++c;
	if (arr[1] == arr[2])
		++c;

	if (c == 3)
		cout << 10000 + arr[1] * 1000;
	else if (c == 2)
		cout << 1000 + arr[1] * 100;
	else if (c == 1)
		cout << arr[2] * 100;
}