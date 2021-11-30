/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Kosaraju
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

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

vector <int> g[MaxN], gt[MaxN];
bitset <MaxN> visited;

stack <int> st;

int comp[MaxN];

void dfs(int u) {
    visited[u] = true;
    for(int x : g[u]) {
        if(visited[x])
            continue;
        dfs(x);
    }
    st.push(u);
}

void dfs2(int u, int id) {
    comp[u] = id;
    for(int x : gt[u]) {
        if(comp[x])
            continue;
        dfs2(x, id);
    }
}

void solve() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++) {
        int di;
        scanf("%d", &di);
        for(int j = 1; j <= di; j++) {
            int v;
            scanf("%d", &v);
            g[i].emplace_back(v);
            gt[v].emplace_back(i);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    int cnt = 0;
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        if(comp[u])
            continue;
        dfs2(u, ++cnt);
    }
    while(q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf(comp[u] == comp[v] ? "yes\n" : "no\n");
    }
}

int main() {
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
4 4 2
2 2 4
1 3
1 1
0
3 1
1 4
*/