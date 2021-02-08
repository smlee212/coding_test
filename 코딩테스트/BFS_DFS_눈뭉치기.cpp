엘리스 토끼와 친구들은 100개의 양동이에 눈을 담았습니다. 그리고 100개의 양동이 중 k개를 고르고, 그중에서 5개를 선택해 눈덩이를 만들기로 했습니다.

예를 들어, 양동이를 7개 고르고, 양동이의 번호가 1, 3, 10, 15, 37, 60, 88인 경우 눈덩이를 만들 수 있는 경우는 (1 3 10 15 37), (1 3 10 15 60), (1 3 10 15 88), … , (10 15 37 60 88)로 총 21개입니다.

양동이의 개수와 양동이의 번호를 입력했을 때, 눈덩이를 만드는 모든 방법을 구하는 프로그램을 작성해 봅시다.
//
입력
첫 번째 입력하는 숫자는 정수 k이고, 다음 k개의 숫자는 양동이의 집합 B에 포함되는 수입니다. B의 원소는 정수이며, 오름차순으로 입력됩니다. (5 < k < 10, 1≤B_{n}B 
n ≤100)
//
출력
양동이를 고르는 모든 방법이 사전 순으로 출력됩니다.
//
입력 예시 Ⅰ
6 1 10 15 20 25 30

출력 예시 Ⅰ
1 10 15 20 25
1 10 15 20 30
1 10 15 25 30
1 10 20 25 30
1 15 20 25 30
10 15 20 25 30
//
입력 예시 Ⅱ
7 1 3 10 15 37 60 88

출력 예시 Ⅱ
1 3 10 15 37
1 3 10 15 60
1 3 10 15 88
1 3 10 37 60
1 3 10 37 88
1 3 10 60 88
1 3 15 37 60
1 3 15 37 88
1 3 15 60 88
1 3 37 60 88
1 10 15 37 60
1 10 15 37 88
1 10 15 60 88
1 10 37 60 88
1 15 37 60 88
3 10 15 37 60
3 10 15 37 88
3 10 15 60 88
3 10 37 60 88
3 15 37 60 88
10 15 37 60 88

///////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAX 100 + 1
int n;
int m = 5; // n개 중 5개 선택
vector<int> v;
deque<int> q;
vector<bool> visited;

void P(int start, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << q[i] << ' ';
        }
        cout << endl;
        return;
    }   

    for (int i = start; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            q.push_back(v[i]);
            cnt++;
            P(i, cnt);
            visited[i] = false;
            q.pop_back();
            cnt--;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
    int data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        v.push_back(data);
        visited.push_back(false);
    }
    sort(v.begin(), v.end());
 
    for (int i = 0; i <= n - m; i++) {
        visited[i] = true;
        q.push_back(v[i]);
        P(i, 1);
        visited[i] = false;
        q.pop_back();
    }
	return 0;
}