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
    int n;
    cin >> n;
    int r = 1, c = 0, m = 0, cc =0;
    set<int> ss;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            int t = 0;
            while (n % i == 0)n /= i, t++;
            ss.insert(t);
            m = max(m, t);
            r *= i;
        }
    }
    for (int x: ss) {
        if(((x - 1) & x) != 0) c = 1;
    }
    if(ss.size() >= 2)c = 1;
    while ((1 << (cc)) < m) cc++;
    cout << r << " " << c + cc << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
