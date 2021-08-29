#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

int n, m;
int d[1 << 17];
int pos[17][200005];
string v;

bool can(int min_k) {
    int cur = -1, cnt = 0, cnt2 = 0;

    for (int j = 0; j < m; j++)pos[j][n] = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == '?') cnt++;
        else {
            int x = v[i] - 'a';
            if (cur == -1 || cur == x) cnt++;
            else cnt = cnt2 + 1;
            cur = x;
        }
        cnt2 = v[i] == '?' ? cnt2 + 1 : 0;

        for (int j = 0; j < m; j++)pos[j][i] = -1;
        if (cnt2 >= min_k)
            for (int j = 0; j < m; j++)pos[j][i] = i;
        else if (cnt >= min_k)
            pos[cur][i] = i;

        for (int j = 0; j < m; j++) {
            if (pos[j][i] == -1)pos[j][i] = pos[j][i + 1];
        }
    }

    int M = 1 << m, Max = 1 << 30;
    d[0] = 0;
    for (int i = 1; i < M; i++) {
        d[i] = Max;
        for (int k = 0; k < m; k++) {
            if (i >> k & 1) {
                int p = i ^ (1 << k);
                if (d[p] == Max) continue;

                int nxt = pos[k][d[p]];
                if (nxt == -1) continue;

                d[i] = min(d[i], nxt + min_k);
            }
        }
    }
    return d[M-1] != Max;
}

void solve() {
    cin >> n >> m >> v;

    int s = 1, e = n / m, r = 0;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (can(mid)) s = mid + 1, r = mid;
        else e = mid - 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
