/*#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int main() {
    // 각 플레이어의 카드 정보를 입력받습니다.
        cin >> n;
            for(int i = 1; i <= n; i++) cin >> a[i];
                for(int i = 1; i <= n; i++) cin >> b[i];
                    
                        // dp 배열을 초기화합니다. 초기값은 -1로 설정합니다.
                            for(int i = 0; i <= n; i++)
                                    for(int j = 0; j <= n; j++) dp[i][j] = -1;

                                        // 기본 케이스를 설정합니다.
                                            dp[0][0] = 0;

                                                // 각 경우의 수를 동적 프로그래밍으로 계산합니다.
                                                    // dp[i][j] :: 첫 번째 플레이어는 i번 카드까지, 두 번째 플레이어는 j번 카드까지 버렸을 때 나올 수 있는 최대 점수
                                                        for(int i = 0; i < n; i++) {
                                                                for(int j = 0; j < n; j++) {
                                                                            if(dp[i][j] == -1) continue;

                                                                                        // 카드 대결 - 첫 번째 플레이어의 카드가 더 작은 경우
                                                                                                    if(a[i + 1] < b[j + 1])
                                                                                                                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

                                                                                                                                // 카드 대결 - 두 번째 플레이어의 카드가 더 작은 경우
                                                                                                                                            if(a[i + 1] > b[j + 1])
                                                                                                                                                            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + b[j + 1]);

                                                                                                                                                                        // 카드 버리기
                                                                                                                                                                                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
                                                                                                                                                                                            }
                                                                                                                                                                                                }

                                                                                                                                                                                                    // 결과를 계산하여 출력합니다.
                                                                                                                                                                                                        int ans = 0;
                                                                                                                                                                                                            for(int i = 0; i <= n; i++) {
                                                                                                                                                                                                                    ans = max(ans, dp[i][n]);
                                                                                                                                                                                                                            ans = max(ans, dp[n][i]);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                    cout << ans;
                                                                                                                                                                                                                                    }