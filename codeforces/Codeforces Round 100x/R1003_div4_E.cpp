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
    int n, m, k;
    cin >> n >> m >> k;
    if (ab(n - m) > k || max(n, m) < k)cout << -1 << endl;
    else {
        char t = '0';
        if (n < m)swap(n, m), t = '1';
        string r = "";
        for (int i = 0; i < k; i++)r += t, n--;
        while (true) {
            if (m == 0)break;
            r += (t == '0' ? '1' : '0');
            m--;
            if (n == 0)break;
            r += t;
            n--;
        }
        while (n--)r += t;
        while (m--)r += (t == '0' ? '1' : '0');
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
