#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int n, m, M;
int a[1000];
int dp[1001][10001]; //DPテーブル

void solve(){
    //一つも選ばない方法は常に一通り
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            if(j - 1 - a[i] >= 0){
                //引き算が含まれる場合には負の数にならないように注意する
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
            }
            else{
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
            }
        }
    }
    printf("%d\n", dp[n][m]);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> M;
    
    solve();

    return 0;
}