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
    int n, m, k;
    string a, b;
    cin >> n >> m >> k >> a >> b;
    vi cnt(2);
    string r;
    while (!a.empty() && !b.empty()) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if ((a <= b && cnt[0] < k) || cnt[1] >= k) {
            r += a[0];
            a = a.substr(1);
            cnt[0] += 1;
            cnt[1] = 0;
        } else {
            r += b[0];
            b = b.substr(1);
            cnt[1] += 1;
            cnt[0] = 0;
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
