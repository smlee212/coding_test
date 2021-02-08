코더 랜드에 코더 바이러스라는 무서운 전염병이 발생했습니다. 바이러스는 1번부터 N 번까지의 카드 병정이 사는 카드 병정의 기숙사 내에서 발생하였으며 1번 카드 병정이 코더 바이러스에 확진이 되었다고 합니다.

코더 바이러스는 사람과 사람 사이에도 전염이 된다고 합니다. 그래서 하트 여왕은 예방을 위해 1번 카드 병정과 접촉한 병정과 1번 카드 병정과 직접 접촉한 병정과 접촉한 병정까지의 사람을 격리하려고 합니다.

하트 여왕은 최근에 접촉한 병정들의 정보를 모두 조사한 리스트를 가지고 있습니다. 이 리스트를 보고 격리해야 할 카드 병정의 수를 구하는 프로그램을 작성하세요.

단, 1번 카드 병정은 이미 격리되었습니다.
//
입력
첫째 줄에 카드 병정의 수 N이 입력됩니다.
(2 ≤ N ≤ 500)
(2≤N≤500)
둘째 줄에는 접촉 정보의 개 m이 입력됩니다.
(1 ≤ m ≤ 1,000)
(1≤m≤1,000)
다음 줄부터 m개 줄에는 접촉 정보 a_i, b_i 가 입력됩니다.
(1 ≤ a_i < b_i ≤ N)
(1≤a_i<b_i≤N)
a_i와 b_i가 접촉했다는 뜻이며, b_i와 a_i도 접촉한 것입니다.
//
출력
2번부터 N 번까지의 카드 병정 중 격리해야 할 병정의 수를 출력합니다. 1번과 접촉한 환자가 없으면 -1을 출력합니다.
//
입력 예시Ⅰ
2
1
1 2

출력 예시Ⅰ
1
//

입력 예시Ⅱ
6
5
1 2
1 3
3 4
2 3
4 5

출력 예시Ⅱ
3

//////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAX 501
int n, m;
int parent[MAX];
int cnt = 0;

int find_parent(int x) {
	if (parent[x] != x) {
		cnt++;
		parent[x] = find_parent(parent[x]);
	}
	return parent[x];
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	int a, b, cycle = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if ((find_parent(a) == find_parent(b)) && find_parent(a) == 1) {
			cycle++;
		}
		else
			union_parent(a, b);
	}

	int res = 0;
	for (int i = 2; i <= n; i++) {
		cnt = 0;
		if (find_parent(i) == 1 && cnt <= 2) {
			res++;
		}
	}
	if (res == 0) {
		res = -1;
	}

	cout << res - cycle << endl;

	return 0;
}