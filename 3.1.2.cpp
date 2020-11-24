#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int N, K;
double L[10000];
const ll INF = 1LL << 60;

//条件を満たすか判定
bool C(double x){
    int num = 0;
    for(int i = 0; i < N; i++){
        num += (int)(L[i]/x);
    }
    return num >= K;
}

void solve(){
    //解の存在範囲の初期化
    double lb = 0, ub = INF;

    //解の存在範囲が十分狭くなるまで繰り返す
    for(int i = 0; i < 100; i++){
        double mid = (lb + ub) / 2;
        if(C(mid)){
            lb = mid;
        }
        else{
            ub = mid;
        }
    }
    printf("%.2f\n", floor(ub * 100) / 100);
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> L[i];
    }
    solve();
}