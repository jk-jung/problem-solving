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
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    vector<vi> A(n + 1, vi(26)), B(n + 1, vi(26));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 26; k++) {
            A[i + 1][k] += A[i][k];
            B[i + 1][k] += B[i][k];
        }
        A[i + 1][a[i] - 'a']++;
        B[i + 1][b[i] - 'a']++;
    }

    while (q--) {
        int s, e;
        cin >> s >> e;
        int r = 0;
        for (int i = 0; i < 26; i++) {
            int x = A[e][i] - A[s - 1][i];
            int y = B[e][i] - B[s - 1][i];
            r += ab(x - y);
        }
        cout << r / 2 << endl;
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
