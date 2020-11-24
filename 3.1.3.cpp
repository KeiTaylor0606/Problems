#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

const ll INF = 1LL << 60;

int N, M;
int x[100000];

bool C(int d){
    int last = 0;
    for(int i = 1; i < M; i++){
        int crt = last + 1;
        while (crt < N && x[crt] - x[last] < d)
        {
            crt++;
        }
        if(crt == N){
            return false;
        }
        last = crt;
    }
    return true;
}

void solve(){
    //初めにxをソートしておく
    sort(x, x + N);

    //解の存在範囲を初期化
    ll lb = 0, ub = INF;

    while (ub - lb > 1)
    {
        int mid = (lb + ub) / 2;
        if(C(mid)){
            lb = mid;
        }
        else{
            ub = mid;
        }
    }

    printf("%d\n", lb);
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    solve();
    return 0;
}