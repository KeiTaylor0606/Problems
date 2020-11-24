#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int n, k;
int a[1000000];

void solve(){
    //解の存在範囲の初期化
    int lb = -1, ub = n;

    //解の存在範囲が1より大きい間、繰り返す。
    while (ub - lb > 1)
    {
        int mid = (lb + ub) / 2;
        if(a[mid] >= k){
            //midが条件を満たせば、解の存在範囲は[lb, mid)
            ub = mid;
        }
        else
        {
            //midが条件を満たさなければ、解の存在範囲は(mid, ub]
            lb = mid;
        }
    }
    //この時点でlb + 1 = ubとなっている
    printf("%d\n", ub);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;
    solve();
}