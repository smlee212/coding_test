코더랜드에서 가장 잘나가는 맛집은 체셔의 식당입니다. 손님이 항상 물밀 듯이 몰려와서 손님 수에 맞춰 요리를 내는 것이 너무 버거웠습니다. 그래서 체셔는 모든 손님에게 대기 시간을 부여하기로 했습니다. 식당으로 들어가는 입구는 하나이며 한 번에 한 손님만 들어올 수 있습니다.

체셔는 최대한 손님을 여유롭게 받기 위해 한 번에 한 손님의 대기 시간만 줄어들도록 하였습니다. 예를 들어, 5분에 도착한 손님이 7분의 대기 시간을 가지고 있으면, 8분에 도착한 손님의 대기 시간은 12분이 되어야 줄어들기 시작하여 20분에 입장할 수 있게 됩니다.

N 명의 손님과 각 손님의 대기 시간이 주어졌을 때, 모든 손님이 입장하려면 얼마나 걸리는지 구하는 프로그램을 작성하세요.

입력
첫 줄에 100 이하의 양의 정수 N이 입력됩니다.
다음 N 줄에는 한 줄에 하나씩 손님의 도착 시각과 대기 시간이 공백으로 구분되어 입력됩니다. 각각 1,000 이하의 양의 정수입니다.

출력
모든 손님이 식당에 입장하는 데 걸리는 최소 시간을 출력합니다.

입력 예시Ⅰ
3
2 1
8 3
5 7

출력 예시Ⅰ
15

입력 예시Ⅱ
1
10 10

출력 예시Ⅱ
20

////////////////////////////////////////////////////////


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAX 1000 * 1000 + 1
int n;
int T[MAX] = { 0, }; // 도착시간 1분 ~ 1000분 + 대기시간 0분 ~ 1000분
int Mintime = MAX;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    int index, data, sum = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> index >> data;
        T[index] = data;
    }

    int i = 0;
    while (cnt < n) {
        if (T[i]) {
            if (sum) {
                sum -= 1;
            }
            sum += T[i];
            cnt++;
        }
        else {
            if (sum > 0) {
                sum--;
            }
        }
        i++;
    }

    cout << i - 1 + sum << endl;
}