엘리스 토끼는 길이가 L인 롤케이크를 사 왔습니다. 엘리스 토끼는 동생들에게 케이크를 나누어 주기 위해 롤케이크를 자르려고 합니다. 롤케이크는 빵이 망가지지 않기 위해서 특정한 위치에서만 자를 수 있습니다.

※ 특정한 위치는 롤케이크의 가장 왼쪽에서부터 떨어진 거리입니다.

엘리스 토끼는 많아야 C 번 케이크를 자르면서 가장 긴 조각의 길이가 최소가 되도록 하려고 합니다. 케이크를 잘랐을 때 가장 긴 조각의 길이와 처음 자르는 위치를 출력하는 프로그램을 작성하세요.
//
입력
첫 번째 줄에 정수인 L, 롤케이크를 자를 수 있는 위치의 개수 K, 롤케이크를 자를 수 있는 횟수 C를 입력합니다.
(1≤L≤10,000)
(1≤L≤10,000)
(1≤C, K≤1,000)
(1≤C,K≤1,000)

두 번째 줄에 롤케이크를 자를 수 있는 위치를 입력합니다.

※ 입력값은 모두 자연수입니다.
//
출력
첫 번째 줄에 케이크를 잘랐을 때 가장 긴 조각의 길이와 처음 자르는 위치를 출력합니다.
※ 만약 가능한 경우가 여러 가지라면, 처음 자르는 위치가 작은 것을 출력합니다.
//
입력 예시Ⅰ
10 2 1
4 5

출력 예시Ⅰ
5 5
//

입력 예시Ⅱ
7 3 1
1 4 3

출력 예시Ⅱ
4 3

/////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAX 50
int l, c, k;
vector<int> v;

// 길이 L, 자를 수 있는 위치 개수 K, 횟수 C
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> l >> k >> c;
	int data;
	for (int i = 0; i < k; i++) {
		cin >> data;
		v.push_back(data);
	}
	sort(v.begin(), v.end());

	int start = 0;
	int end = l;
	int Min = 10001;
	int cut;

	while (start <= end) {
		int vmid = v.size() / 2;
		int mid = (end - start) / 2;
		if (vmid == mid) {
			cut = end - mid;
			Min = min(Min, cut);
		}
		else if () {

		}
		else {

		}
		
	}

	
	return 0;
}
