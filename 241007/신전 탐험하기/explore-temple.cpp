/*#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    return 0;
}*/
#include <iostream>
using namespace std;

int n;
int a[1005][5];
int dp[1005][5];

int main() {
    // 각 층의 보물의 개수 정보를 입력받습니다.
        cin >> n;
            
                for(int i = 1; i <= n; i++) {
                        for(int j = 1; j <= 3; j++)
                                    cin >> a[i][j];
                                        }

                                            // 동적 프로그래밍을 사용하여 최대 점수를 계산합니다.
                                                // dp[i][j] : i번째 층까지 올라왔을 때,
                                                    // j번 방(j = 1일 때 : 왼쪽, j = 2일 때 : 가운데, j = 3일 때 : 오른쪽)
                                                        // 을 골랐을 때 가져갈 수 있는 보물의 최대 개수
                                                            for(int i = 0; i < n; i++) {
                                                                    for(int j = 1; j <= 3; j++) {
                                                                                for(int k = 1; k <= 3; k++) {
                                                                                                // 이전 층과 같은 방을 고르지 않는 경우에 대해 계산합니다.
                                                                                                                if(j != k) {
                                                                                                                                    dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + a[i + 1][k]);
                                                                                                                                                    }
                                                                                                                                                                }
                                                                                                                                                                        }
                                                                                                                                                                            }

                                                                                                                                                                                // 최종적으로 가능한 최대 점수를 계산합니다.
                                                                                                                                                                                    int ans = 0;
                                                                                                                                                                                        for(int j = 1; j <= 3; j++) {
                                                                                                                                                                                                ans = max(ans, dp[n][j]);
                                                                                                                                                                                                    }

                                                                                                                                                                                                        // 계산된 최대 점수를 출력합니다.
                                                                                                                                                                                                            cout << ans;
                                                                                                                                                                                                                return 0;
                                                                                                                                                                                                                }