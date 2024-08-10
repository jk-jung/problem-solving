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
    if (n < 3)cout << -1;
    else if (n == 3) cout << 210;
    else {
        int t = 1;
        for (int i = 0; i < n - 1; i++) {
            t = (t * 10) % 210;
        }
        int c = 0;
        while (t) {
            t = (t + 1) % 210;
            c++;
        }
        string r = to_string(c);
        cout << 1;
        for (int i = 0; i < n - 1 - r.size(); i++)cout << 0;
        cout << r;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
