#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

#define MAX 20
int tc, n, m;
int res = 0;
int dp[MAX][MAX] = { 0, };
int arr[MAX][MAX] = { 0, };

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> tc;
    int data;
    int left_up, left_down, left;

    while (tc--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) { // dp, arr 행렬 입력
                cin >> data;
                arr[i][j] = dp[i][j] = data;
            }
        }

        for (int j = 1; j < m; j++) { // 첫번째 행은 건너뛴다.
            for (int i = 0; i < n; i++) { // 0번째 행부터 n-1번째 행까지 채워넣는다.
                //왼쪽 위에서 왔을 경우
                if (i == 0) left_up = 0; // 왼쪽 위가 없다.
                else left_up = dp[i-1][j-1];

                //왼쪽 아래에서 왔을 경우
                if (i == n - 1) left_down = 0; // 왼쪽 아래가 없다.
                else left_down = dp[i + 1][j + 1];

                //왼쪽에서 왔을 경우
                left = dp[i][j - 1];

                dp[i][j] += max(left, max(left_up, left_down)); // 3가지 경우 중 제일 큰 값을 적용
            }
        }
        res = 0;
        for (int i = 0; i < n; i++) { // 마지막 열(m-1) 중 가장 큰 값을 찾는다.
            res = max(res, dp[i][m - 1]);
        }
        cout << res << endl;
    }

    return 0;
}