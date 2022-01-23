#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
#include <map>
#include <array>
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

int n, k;
string s, ss, r;
vi idx;
bool ck[200005];
int L[200005];
int R[200005];
int last[26];
int doubled[200005];
int p[200005];

void dfs(int x) {
    if (x == -1)return;

    dfs(L[x]);
    ss.pb(s[x]);
    idx.pb(x);
    dfs(R[x]);
}

void go(int x, int cost = 1) {
    if (x == -1) return;

    go(L[x], cost + 1);

    if (ck[x] && !doubled[x] && cost <= k) {
        k -= cost;
        int y = x;
        while (y != -1 && !doubled[y]) {
            doubled[y] = 1;
            y = p[y];
        }
    }

    r += s[x];
    if (doubled[x]) {
        cost = 1;
        r += s[x];
    } else cost = 1 << 20;

    go(R[x], cost);
}

void solve() {
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
        L[i]--, R[i]--;
        p[L[i]] = p[R[i]] = i;
    }
    p[0] = -1;
    dfs(0);

    for (int &x: last)x = -1;
    last[ss.back() - 'a'] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        int x = ss[i] - 'a';
        int y = -1, yi = n + 1;
        for (int j = 0; j < 26; j++) {
            if (j != x && last[j] != -1 && last[j] < yi) {
                yi = last[j];
                y = j;
            }
        }
        last[x] = i;

        if (y == -1 || y < x)continue;
        ck[idx[i]] = true;
    }

    go(0);

    cout << r << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
}
