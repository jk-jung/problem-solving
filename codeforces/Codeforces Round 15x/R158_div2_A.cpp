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
    int a, b, n;
    cin >> a >> b >> n;
    string r = to_string(a);
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int k = 0; k < 10; k++) {
            int m = (a * 10 + k) % b;
            if (m == 0) {
                ok = true;
                r += '0' + k;
                a = m;
                break;
            }
        }
        if (!ok) {
            cout << "-1";
            return;
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
