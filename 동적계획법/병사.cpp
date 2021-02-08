#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

#define MAX 2000
int n;
int Max = 0;
int d[MAX];
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> n;
    int data;
    for (int i = 0; i < n; i++) { // 역순으로 입력받음
        cin >> data;
        dq.push_front(data);
    }

    fill_n(d, n, 1); // 행렬 d를 n-1까지 1로 초기화

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dq[j] < dq[i]) { // LIS 알고리즘 수행
                d[i] = max(d[i], d[j] + 1);
                Max = max(Max, d[i]); // 병사 수가 많을수록 열외자는 적어짐
            }
        }
    }

    cout << n - Max << endl; 

    return 0;
}