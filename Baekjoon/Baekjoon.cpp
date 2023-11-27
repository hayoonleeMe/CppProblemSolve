#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1005];
int d[1005];

#include <random>
void RandomInput()
{
	// 파일 생성
	ofstream HzWriteFile("input.txt");

	// 파일 쓰기
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> disN(1, 10);
	std::uniform_int_distribution<int> dis(1, 200);

	int n = disN(gen);
	HzWriteFile << n << '\n';
	for (int i = 0; i < n; ++i)
	{
		HzWriteFile << dis(gen) << ' ';
	}

	// 파일 닫기
	HzWriteFile.close();
}

int main()
{
	//RandomInput();

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		d[i] = arr[i];
	}

	for (int i = 1; i < N; ++i)
	{
		int mx = 0;
		for (int j = i - 1; j >= 0; --j)
			if (arr[i] > arr[j])
				mx = max(mx, d[j]);

		d[i] += mx;
	}

	cout << *max_element(d, d + N);
}