#include <bits/stdc++.h>
using namespace std;

int N, K;
int a[100'002];
int total;

bool Solve(int mid)
{
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += a[i];		// 앞에서부터 순서대로 그룹핑 (맞은문제 개수 더함)

		if (sum >= mid)		// 기준 점수 넘으면 그룹핑 끝
		{
			++cnt;
			sum = 0;
		}
	}
	
	return cnt >= K;		// 총 생성한 그룹 개수가 조건을 만족하는지 반환
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
		total += a[i];		// 총점 계산
	}

	int st = 0;
	int en = total;			// 총 맞은 문제의 개수 = 가능한 최대 기준
	while (st < en)
	{
		int mid = (st + en + 1) / 2;	// st = mid 이므로 무한 반복 방지 위해 1 더함
		if (Solve(mid))
			st = mid;					// 조건 만족, 최대값 찾아야 하니까 기준점수를 더 키워서 다시 탐색
		else
			en = mid - 1;				// 조건 불만족, 그룹을 더 많이 만들수 있도록 기준 점수를 낮춤
	}
	cout << st;
}

//8 3
//12 7 19 20 17 14 9 10
//
//parametric.....................
//
//문제 개수의 합 최소를 찾음
//합 최소 커지면 생성 가능 그룹 수 줄어듬
//		작아지면 생성 가능 그룹 수 늘어남

//순서대로 그룹 정함
//각 그룹의 문제개수 합 중 가장 작은 점수가 답이자 기준 <- 얘를 찾을거임
//앞에서부터 순서대로 그룹으로 모을건데, 기준점수 이상이 되면 그룹 하나 생성 끝
//쭉쭉 그룹생성해서 만들수있는 그룹 개수가 K 이상이면 조건 만족 
//
//기준점수가 커지면 만들수있는 그룹 개수 줄어듬
//기준점수가 작아지면 만들수있는 그룹 개수 늘어남
//
//기준 최대값 찾는것