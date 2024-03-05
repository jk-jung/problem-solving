#include <cstring>
#include <cstdio>
#include <cmath>
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


void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &x: v)cin >> x;

    vector<int> d[255], deg(255);
    for (int i = 1; i < n; i++) {
        bool ok = false;
        string &a = v[i - 1];
        string &b = v[i];
        for (int j = 0; j < min(a.size(), b.size()); j++) {
            if (a[j] != b[j]) {
                ok = true;
                d[a[j]].pb(b[j]);
                break;
            }
        }
        if (!ok && a.size() > b.size()) {
            cout << "Impossible";
            return;
        }
    }
    for (int i = 0; i < 255; i++) {
        sort(d[i].begin(), d[i].end());
        d[i].erase(unique(d[i].begin(), d[i].end()), d[i].end());
        for (int x: d[i])deg[x]++;
    }
    queue<int> q;
    for (int i = 'a'; i <= 'z'; i++)if (deg[i] == 0)q.push(i);
    string r;
    vi visit(255);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        r += x;
        if (visit[x]) {
            cout << "Impossible";
            return;
        }
        visit[x] = 1;
        for (int y: d[x]) {
            if (--deg[y] == 0)q.push(y);
        }
    }
    cout << (r.size() == 26 ? r : "Impossible");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
