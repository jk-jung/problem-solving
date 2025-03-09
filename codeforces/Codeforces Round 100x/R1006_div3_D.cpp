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
    cin >> n;
    vi v(n);
    int r = -1, a = 0, b = 0;
    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = i; j < n; j++) {
            if (v[i] > v[j]) c++;
            if (v[i] < v[j]) c--;
            if (c > r) {
                r = c;
                a = i + 1;
                b = j + 1;
            }
        }
    }

    cout << a << " " << b << endl;
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
