더랜드에서 사업을 하는 엘리스 토끼는 제품에 붙어 있는 시리얼 넘버로 창고를 정리하려고 합니다. 모든 시리얼 번호는 알파벳 대문자 (A-Z)와 숫자 (0-9)로 이루어져 있습니다.

시리얼 번호의 순서를 정하는 규칙은 다음과 같습니다.

A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
만약 서로 길이가 같다면, A의 모든 자릿수의 합과 B의 모든 자릿수의 합을 비교해서 작은 합을 가지는 것이 먼저 온다. (숫자인 것만 더한다)
만약 1, 2번 둘 조건으로도 비교할 수 없으면, 사전 순으로 비교한다. 숫자가 알파벳보다 사전 순으로 작다.
시리얼이 주어졌을 때, 정렬해서 출력하는 프로그램을 작성해봅시다.
//
입력
첫째 줄에 제품의 개수인 자연수 N이 주어집니다. N은 1,000보다 작거나 같습니다.
둘째 줄부터 N개의 줄에 시리얼 번호가 하나씩 주어집니다. 시리얼 번호의 길이는 최대 50이고, 알파벳 대문자 또는 숫자로만 이루어져 있습니다. 시리얼 번호는 중복되지 않습니다.
//
출력
첫째 줄부터 차례대로 N개의 줄에 한 줄에 하나씩 시리얼 번호를 정렬한 결과를 출력합니다.
//
입력 예시Ⅰ
5
ABC
A124
B32
B9
C12

출력 예시Ⅰ
B9
ABC
C12
B32
A124
//
입력 예시Ⅱ
10
A
B
C
D
E
1
2
3
4
5

출력 예시Ⅱ
A
B
C
D
E
1
2
3
4
5

////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
vector<string> v;

bool comp(string a, string b) {
	if (a.size() == b.size()) {
		int asum = 0, bsum = 0;
		for (int i = 0; i < a.size(); i++) {
			asum += isalpha(a[i]) ? 0 : a[i];
			bsum += isalpha(b[i]) ? 0 : b[i];
		}
		if (asum != bsum) {
			return asum < bsum;
		}
		else {
			for (int i = 0; i < a.size(); i++) {
				if (a[i] == b[i]) continue;
				return a[i] < b[i];
			}
		}
	}
	else {
		return a.size() < b.size();
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++) {
		cout << v[i] << endl;
	}

	return 0;
}