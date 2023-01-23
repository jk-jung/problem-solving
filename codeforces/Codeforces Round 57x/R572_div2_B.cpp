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
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (i % 2)q.push_back(v[i]);
        else q.push_front(v[i]);
    }
    for (int i = 0; i < n; i++) {
        int x = (i - 1 + n) % n;
        int y = (i + 1) % n;
        if (q[i] >= q[x] + q[y]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int &x: q)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
