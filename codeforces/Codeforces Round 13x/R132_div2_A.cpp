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

vi read() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    return v;
}

void solve() {
    vi a = read();
    vi b = read();

    int r = 0, c = 0;
    for (int y: b)
        for (int x: a) {
            if (y % x == 0) {
                int d = y / x;
                if (d > c) {
                    c = d;
                    r = 1;
                } else if (d == c) {
                    r++;
                }
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
