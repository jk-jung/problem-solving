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

int n;
vi v[2005];
int p[2005];
int c[2005];
int num[2005];
int r[2005];
int used[2005];
int root;


int dfs1(int x) {
    num[x] = 1;
    for (int y: v[x])num[x] += dfs1(y);
    return num[x];
}

void dfs(int x, int e = n) {
    int tar = -1;
    for (int i = 1; i <= e; i++) {
        if (used[i])continue;
        if (c[x] == 0) {
            tar = i;
            break;
        }
        c[x]--;
    }
    if (tar == -1) {
        cout << "NO\n";
        exit(0);
    }
    used[tar] = 1;
    r[x] = tar;

    int i = 1;
    for (int y: v[x]) {
        int cnt = 0, ee = 0;
        for (; i <= n; i++) {
            if(used[i])continue;
            cnt ++;
            if(cnt == num[y]) {
                ee = i;
                break;
            }
        }
        dfs(y, ee);
    }
}


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> c[i];
        p[i]--;
        if (p[i] == -1)root = i;
        else v[p[i]].pb(i);
    }
    dfs1(root);
    dfs(root);
    cout << "YES\n";
    for (int i = 0; i < n; i++)cout << r[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
