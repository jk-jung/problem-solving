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
    int n, k;

    cin >> n >> k;
    vi v(n);
    int r = 0;
    for (int &x: v)cin >> x;
    for (int i = 0; i < k; i++) {
        int a = 0, b = 0;
        for (int j = 0; j < n; j++) {
            if (j % k != i) {
                if (v[j] == -1)a++;
                else b++;
            }
        }
        r = max(r, ab(a - b));
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
