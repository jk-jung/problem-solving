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
    if (n == 2)cout << "YES";
    else {
        vi v;
        while (m)v.pb(m % n), m /= n;
        v.pb(0);
        reverse(v.begin(), v.end());
        v.pb(0);

        for (int i = 0; i < v.size(); i++) {
            bool ok = true;
            if (v[i] == 0 || v[i] == 1);
            else if (v[i] == n - 1) {
                if (v[i - 1] != 0 && v[i - 1] != n - 2 && v[i - 1] != n - 1) ok = false;
            } else if (v[i] == n - 2) {
                if (v[i - 1] != 0 && v[i - 1] != n - 2) ok = false;
                if (v[i + 1] != n - 2 && v[i + 1] != n - 1)ok = false;
            } else ok = false;

            if (!ok) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
