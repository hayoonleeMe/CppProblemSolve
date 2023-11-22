#include <bits/stdc++.h>
using namespace std;

int L, C;
char arr[20];
int mask[20];

// next_permutation 사용
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; ++i)
		cin >> arr[i];
	sort(arr, arr + C);

	for (int i = L; i < C; ++i)
		mask[i] = 1;

	do
	{
		// 모음 자음 개수 체크
		int v = 0, c = 0;
		for (int i = 0; i < C; ++i)
		{
			if (!mask[i])
			{
				if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
					++v;
				else
					++c;
			}
			
		}
		// 출력
		if (v >= 1 && c >= 2)
		{
			for (int i = 0; i < C; ++i)
				if (!mask[i])
					cout << arr[i];
			cout << '\n';
		}
	} while (next_permutation(mask, mask + C));
}