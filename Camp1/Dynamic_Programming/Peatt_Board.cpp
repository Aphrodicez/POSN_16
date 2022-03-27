/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e3 + 10;

int dp[MaxN][MaxN];

int main() {
    int r, c, n;
    scanf("%d %d %d", &c, &r, &n);
    while(n--) {
        int sti, stj, eni, enj;
        scanf("%d %d %d %d", &stj, &sti, &enj, &eni);
        dp[sti][stj]++;
        dp[sti][enj + 1]--;
        dp[eni + 1][stj]--;
        dp[eni + 1][enj + 1]++;
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            printf("%d", dp[i][j] % 2);
        }
        printf("\n");
    }
    return 0;
}

/*
13 8 3
4 2 11 5
3 3 7 8
7 5 12 6
*/