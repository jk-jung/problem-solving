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


int n, m;
int p[100005][32];
int a[100005];
int r[100005];
int in_deg[100005];
int used[100005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> p[i][0], in_deg[p[i][0]]++;
    for (int i = 1; i <= n; i++)cin >> a[i];

    int cnt = 0;
    for (int i = 1; i <= n; i++)if (in_deg[i] >= 2)cnt += in_deg[i] - 1;
    for (int i = 1; i <= n; i++)m = max(m, (a[i] - n) / cnt);

    for (int k = 1; k < 31; k++)for (int i = 1; i <= n; i++)p[i][k] = p[p[i][k - 1]][k - 1];


    for (int i = 1; i <= n; i++) {
        int x = i;
        for (int k = 0; k < 31; k++)if (m >> k & 1)x = p[x][k];
        if (used[a[x]])continue;
        used[a[x]] = 1;
        r[i] = a[x];
    }

    set<int> ck;
    for (int i = 1; i <= n; i++)if(!used[i])ck.insert(i);

    for (int i = 1; i <= n; i++) {
        int x = i;
        for (int k = 0; k < 31; k++)if (m >> k & 1)x = p[x][k];
        if (r[i])continue;
        auto it = ck.lower_bound(a[x]);
        r[i] = *it;
        ck.erase(it);
    }

    for(int i=1;i<=n;i++)cout<< r[i] <<" ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
