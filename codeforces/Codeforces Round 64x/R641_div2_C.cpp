#include <string.h>
#include <stdio.h>
#include <math.h>
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

void update(set<int> &s, int x) {
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0)x /= i, s.insert(i);
    }
    if (x > 1)s.insert(x);
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v) cin >> x;
    set<int> pr;

    update(pr, v[0]);
    update(pr, v[1]);

    ll r = 1;
    for (int p: pr) {
        int c1 = 1 << 30, c2 = 1 << 30;
        for (int x: v) {
            int c = 0;
            while (x % p == 0)c++, x /= p;

            if (c1 >= c) {
                c2 = c1;
                c1 = c;
            } else if (c2 > c) {
                c2 = c;
            }
        }
        for (int i = 0; i < max(c1, c2); i++)r *= p;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
