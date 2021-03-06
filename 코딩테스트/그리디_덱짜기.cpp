레전드 오브 트럼프는 빨간 카드 3장과 검은 카드 2장을 하나의 덱으로 만들어 싸우는 카드 게임입니다.

엘리스 토끼는 빨간 카드 A 장과 검은 카드 B 장으로 덱을 만들려고 합니다. 그런데 너무 좋은 카드들이 많아져서 이번 대회에서는 k 장을 무조건 빼야 한다는 룰이 생겼습니다.

엘리스 토끼는 최대한 많은 카드 덱을 만들려고 합니다.

엘리스 토끼를 도와 빨간 카드, 검은 카드, 빠져야 하는 카드의 수가 주어졌을 때, 짤 수 있는 덱 개수의 최댓값을 구해봅시다.
//
입력
A, B, K를 공백으로 구분해서 입력합니다.
(0 ≤ A, B ≤ 200)
(0≤A,B≤200)
(0 ≤ K ≤ A+B)
(0≤K≤A+B)
//
출력
만들 수 있는 덱의 최댓값을 출력합니다.
//
입력 예시Ⅰ
6 5 1

출력 예시Ⅰ
2

입력 예시Ⅱ
0 0 0

출력 예시Ⅱ
0

///////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int a, b, k;

void A() {
	if (a % 3 == 2) {
		a -= 2;
		k -= 2;
	}
	else if (a % 3 == 1) {
		a -= 1;
		k -= 1;
	}
	else {
		a -= 3;
		k -= 3;
	}
}

void B() {
	if (b % 2 == 1) {
		b -= 1;
		k -= 1;
	}
	else {
		b -= 2;
		k -= 2;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> b >> k;
	
	while (k > 0) {
		if (a / 3 < b / 2) {
			B();
		}
		else if (a / 3 > b / 2) {
			A();
		}
		else {
			A();
			if (k <= 0) break;
			B();
		}
	}

	cout << max(a / 3, b / 2)<< endl;

	return 0;
}