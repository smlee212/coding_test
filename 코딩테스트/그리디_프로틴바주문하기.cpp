잭은 운동을 하고 나서 먹는 단백질 바를 전부 먹어 새로운 단백질 바를 구매하려고 합니다.

단백질 바는 6개가 들어있는 세트로 구매할 수 있고, 1개 또는 그 이상의 단백질 바를 낱개로 살 수도 있습니다.

브랜드별로 단백질 바의 세트 가격과 낱개 가격이
주어질 때 적어도 N개를 사기 위해 필요한 돈의 최솟값을 출력하는 프로그램을 작성하세요.
//
입력
첫 번째 줄에 구매할 단백질 바의 개수 N과 브랜드의 개수 M을 공백으로 구분하여 입력합니다.
(1≤N≤100)
(1≤N≤100)
(1≤M≤10)
(1≤M≤10)

둘째 줄부터 각 브랜드의 세트 가격 정수 PACKAGE와 낱개의 가격인 정수 ONE을 공백으로 구분하여 입력합니다.
(0≤PACKAGE≤1000)
(0≤PACKAGE≤1000)
(0≤ONE≤1000)
(0≤ONE≤1000)
//
출력
첫 번째 줄에 단백질 바를 적어도 N개 사기 위해 필요한 돈의 최솟값을 출력합니다.
//
입력 예시Ⅰ
4 2
12 3
15 4

출력 예시Ⅰ
12

입력 예시Ⅱ
9 9
13 2
15 3
7 1
9 4
8 2
12 2
13 5
11 2
6 4

출력 예시Ⅱ
9

////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m;
vector<int> pack;
vector<int> one;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		pack.push_back(a);
		one.push_back(b);
	}

	sort(pack.begin(), pack.end());
	sort(one.begin(), one.end());

	int buf, c;
	int p = n / 6, o = n % 6, sum = 0;
	a = 0, b = 0;
	while (p-- >= 0) {

		buf = 0;

		if (p == 0) {
			c = b + o;
		}
		else c = b + 6;

		if (c >= m) {
			buf = pack[a];
		}
		else {
			for (int i = b; i < c; i++) {
				buf += one[i];
			}
		}
		
		
		if (pack[a] <= buf) {
			sum += pack[a];
			a++;
		}
		else {
			sum += buf;
			b += 6;
		}
	}
	cout << sum << endl;

	return 0;
}