#include <bits/stdc++.h>
using namespace std;

int N;
int a[1'000'003];
vector<int> uni;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
		uni.push_back(a[i]);
	}
	sort(uni.begin(), uni.end());

	// unique() : 중복되지 않은 값들을 앞으로 몰아주고 나머지는 쓰레기값 들어감, 쓰레기값이 시작되는 구간을 반환
	// 따라서 모든 쓰레기값을 erase하고 벡터에는 중복되지 않은 값만 남는다.
	uni.erase(unique(uni.begin(), uni.end()), uni.end());

	for (int i = 0; i < N; ++i)
		cout << lower_bound(uni.begin(), uni.end(), a[i]) - uni.begin() << ' ';
}