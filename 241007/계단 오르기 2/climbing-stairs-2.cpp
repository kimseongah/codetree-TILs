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
int coin[MAXN];
int dp[MAXN][5];

int main() {
    // 계단의 층 수를 입력받습니다.
        cin >> n;
            // 각 층의 동전의 개수를 입력받습니다.
                for(int i = 1; i <= n; i++)
                        cin >> coin[i];
                            
                                // 기본 케이스를 초기화합니다.
                                    dp[1][1] = coin[1];

                                        dp[2][0] = coin[2];
                                            dp[2][2] = coin[1] + coin[2];

                                                // 동적 프로그래밍을 사용하여 최대 가치를 계산합니다.
                                                    // dp[i][j] : i번 위치에 도착했을 때, 정확히 j번 1계단 올랐을 때의 최대 가치
                                                        for(int i = 3; i <= n; i++) {
                                                                for(int j = 0; j <= 3; j++) {
                                                                            if (dp[i - 2][j] != 0)
                                                                                            dp[i][j] = max(dp[i][j], dp[i - 2][j] + coin[i]);
                                                                                                        if(j && dp[i - 1][j - 1] != 0)
                                                                                                                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + coin[i]);
                                                                                                                                }
                                                                                                                                    }

                                                                                                                                        // 가능한 모든 경우에서 최대 가치를 찾아 출력합니다.
                                                                                                                                            int ans = 0;
                                                                                                                                                for(int j = 0; j <= 3; j++)
                                                                                                                                                        ans = max(ans, dp[n][j]);
                                                                                                                                                            
                                                                                                                                                                cout << ans;
                                                                                                                                                                }