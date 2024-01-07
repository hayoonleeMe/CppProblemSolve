﻿#include <bits/stdc++.h>
using namespace std;

int N, K, w, v;
// W, V
int W[102], V[102];
// d[i] : 물품의 개수가 i개일 때 최대 가치합
int d[102][100'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		cin >> w >> v;
		W[i] = w;
		V[i] = v;
	}

	for (int k = 1; k <= K; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			// i번째 물건을 배낭에 못넣을때
			if (W[i] > k)
				d[i][k] = d[i - 1][k];
			else
				// i번째 물건 안넣기 vs 넣기
				d[i][k] = max(d[i - 1][k], V[i] + d[i - 1][k - W[i]]);
		}
	}

	cout << d[N][K];
}

// 0-1 Knapsack
//K=7
//w v
//6 13
//4 8
//3 6
//5 12
//
//d[i][k] : 무게제한이 k일 때, 1번째부터 i번째 물건까지 담을 수 있는 최대 가치
//d[1][1] = 0 
//d[2][1] = 0
//~
//d[4][1] = 0
//
//d[1][2] = 0
//~
//d[4][2] = 0
//
//d[1][3] = 0
//d[2][3] = 0
//d[3][3] = 6 = max(d[2][3], V[3] + d[2][0])
//d[4][3] = 6 = d[3][3]
//
//d[1][4] = 0 = d[0][4]
//d[2][4] = 8 = max(d[1][4], V[2] + d[1][0]) 
//d[3][4] = 8 = max(d[2][4], V[3] + d[2][1])
//d[4][4] = 8 = d[3][4]
//
//d[1][5] = 0
//d[2][5] = 8 = max(d[1][5], V[2] + d[1][1])
//d[3][5] = 8 = max(d[2][5], V[3] + d[2][3])
//d[4][5] = 12 = max(d[3][5], V[4] + d[3][0])
//
//d[1][6] = 13 = max(d[0][6], V[1] + d[0][0])
//d[2][6] = 13 = V[]
//d[3][6] = 13
//d[4][6] = 13
//
//d[1][7] = 13
//d[2][7] = 13
//d[3][7] = 14 = max(d[2][7], V[3] + d[2][4])
//d[4][7] = 14 
