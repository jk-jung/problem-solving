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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &x: v)cin >> x;

    int r = 0;
    while (true) {
        vector<string> t = v;
        sort(t.begin(), t.end());
        if (t == v)break;
        r++;
        for (int j = 0; j < v[0].size(); j++) {
            bool ok = false;
            for (int i = 1; i < n; i++) {
                if (v[i].substr(0, j + 1) < v[i - 1].substr(0, j + 1))ok = true;
            }
            if (ok) {
                for (int i = 0; i < n; i++) {
                    v[i] = v[i].substr(0, j) + v[i].substr(j + 1);
                }
                break;
            }
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
