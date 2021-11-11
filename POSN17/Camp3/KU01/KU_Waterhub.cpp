/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Brute Force Algorithm + Math
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

long long x[MaxN], y[MaxN];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    long long ans = 1e18;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j == i)
                continue;
            long long sum = 0;
            for(int k = 1; k <= n; k++) {
                if(k == i || k == j)
                    continue;
                sum += min(abs(x[i] - x[k]) + abs(y[i] - y[k]), abs(x[j] - x[k]) + abs(y[j] - y[k]));
            }
            ans = min(ans, sum);
        }
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
    
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
4
1 2
4 3
7 1
8 3

6
1 1
3 2
2 4
8 1
4 3
8 3
*/