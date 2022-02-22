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

vector<pi> v[200005];
vector<int> v2[200005];
int pos[200005];
int deg[200005];
int ox[200005];


// 0 ->  <- 1
bool dfs(int x, int dir = 1) {
    pos[x] = dir;
    int nt = 3 - dir;
    for (auto[z, t]: v[x]) {
        // irrelevant
        if(dir == 1) {
            if(t == 1)v2[z].pb(x), deg[x]++;
            else v2[x].pb(z), deg[z]++;
        }

        if (pos[z]) {
            if (pos[z] != nt)return false;
            else continue;
        }
        if (!dfs(z, nt)) return false;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi ty(m), a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> ty[i] >> a[i] >> b[i];
        v[a[i]].pb(pi(b[i], ty[i]));
        v[b[i]].pb(pi(a[i], ty[i]));

    }

    for (int i = 1; i <= n; i++) {
        if (pos[i] == 0 && !dfs(i)) {
            cout << "NO";
            return;
        }
    }

    queue<int> q;
    int x = 0;
    for (int i = 1; i <= n; i++)if (deg[i] == 0) q.push(i);
    while (!q.empty()) {
        int k = q.front();
        q.pop();

        ox[k] = ++x;
        for (int z: v2[k])if (--deg[z] == 0)q.push(z);
    }
    for(int i=1;i<=n;i++) {
        if(ox[i] == 0){
            cout << "NO";
            return;
        }
    }
    cout << "YES\n";
    for(int i=1;i<=n;i++){
        cout<< (pos[i] == 1 ? "R "  : "L ") << ox[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
