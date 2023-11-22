#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];

// next_permutation 사용
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		arr[i] = i + 1;

	do
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		// M개 원소를 제외한 뒤의 원소를 뒤집어 다음 next_permutation으로 나올 배열로 미리 만든다.
		// 이를 통해 0 ~ M-1 원소가 중복되지 않도록 한다.
		// N=4, M=2일 때, 12 34, 12 43은 중복되므로 12 34를 처리하고 next_permutation을 돌리기 전에
		// 배열을 12 43으로 만들어 next_permutation이 12 43 다음 조합을 생성하도록 한다.
		reverse(arr + M, arr + N);
	} while (next_permutation(arr, arr + N));
}