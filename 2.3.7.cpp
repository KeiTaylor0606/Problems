#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int n, m, M;
int dp[1001][1001];  //DPテーブル

void solve(){
    dp[0][0] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(j - i >= 0){
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d\n", dp[m][n]);
}

int main(){
    cin >> n >> m >> M;
    solve();
    return 0;
}