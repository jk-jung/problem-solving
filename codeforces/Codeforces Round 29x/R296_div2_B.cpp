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

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int r = 0;
    map<string, int> t1;
    for (int i = 0; i < n; i++)if (a[i] != b[i])r++, t1[string(1, a[i]) + string(1, b[i])] = i + 1;

    for (auto &[x, idx]: t1) {
        string y = x;
        reverse(y.begin(), y.end());
        if (t1.count(y)) {
            cout << r - 2 << endl;
            cout << idx << " " << t1[y];
            return;
        }
    }

    for (auto &[x, idx]: t1) {
        for(auto &[y, i2]: t1) {
            if(y[1] == x[0]) {
                cout << r - 1 << endl;
                cout << idx << " " << i2;
                return;
            }
        }
    }

    cout << r << endl;
    cout << "-1 -1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
