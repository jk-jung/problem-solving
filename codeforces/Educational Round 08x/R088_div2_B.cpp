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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int r = 0;
    while (n--) {
        string s;
        cin >> s;

        for (int i = 0; i < m; i++) {
            if (s[i] == '.') {
                if (i + 1 < m && s[i + 1] == '.' && b < a * 2) {
                    r += b;
                    s[i] = s[i + 1] = '*';
                } else {
                    r += a;
                    s[i] = '*';
                }

            }
        }
    }
    cout << r << endl;
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
