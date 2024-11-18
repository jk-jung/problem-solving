#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

int n, m;
set<int> e[1000];

void solve() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].insert(b);
        e[b].insert(a);
    }

    int r = 0;
    while (true) {
        set<int> t;
        for (int i = 1; i <= n; i++) {
            if (e[i].size() == 1)t.insert(i);
        }
        if (t.empty())break;
        for (int i = 1; i <= n; i++) {
            if (t.count(i))e[i].clear();
            for (int x: t) {
                if (e[i].count(x))e[i].erase(x);
            }
        }
        r++;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
