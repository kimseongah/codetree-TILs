/*#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    return 0;
}*/
#include <iostream>
using namespace std;

int n;
int dp[1005][15];

#define MOD 1000000007

int main() {
    // 숫자의 길이 n을 입력받습니다.
        cin >> n;
            
                // 첫 번째 자리에 올 수 있는 숫자들의 경우의 수를 초기화합니다.
                    for(int i = 1; i <= 9; i++) dp[1][i] = 1;

                        // 동적 프로그래밍을 사용하여 각 자리수마다 가능한 숫자들의 합을 계산합니다.
                            // dp[i][j] :: i자릿수 까지 봤을 때, 마지막 숫자가 j인 가짓수
                                for(int i = 1; i < n; i++) {
                                        for(int j = 0; j <= 9; j++) {
                                                    // 숫자가 감소하는 경우를 고려합니다.
                                                                if(j > 0) {
                                                                                dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
                                                                                            }

                                                                                                        // 숫자가 증가하는 경우를 고려합니다.
                                                                                                                    if(j < 9) {
                                                                                                                                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
                                                                                                                                                }
                                                                                                                                                        }
                                                                                                                                                            }

                                                                                                                                                                // 최종 결과를 계산합니다.
                                                                                                                                                                    int ans = 0;
                                                                                                                                                                        for(int j = 0; j <= 9; j++) {
                                                                                                                                                                                ans = (ans + dp[n][j]) % MOD;
                                                                                                                                                                                    }

                                                                                                                                                                                        // 계산된 결과를 출력합니다.
                                                                                                                                                                                            cout << ans;
                                                                                                                                                                                                return 0;
                                                                                                                                                                                                }