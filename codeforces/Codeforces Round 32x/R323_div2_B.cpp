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
    vi v(n), k(n);
    for (int &x: v)cin >> x;
    int c = 0, r = 0;
    while (true) {
        r++;
        for (int i = 0; i < n; i++) {
            if (v[i] <= c) {
                c++;
                v[i] = 1e9;
            }
        }
        if (n == c)break;
        r++;
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] <= c) {
                c++;
                v[i] = 1e9;
            }
        }
        if(n == c)break;
    }
    cout << r - 1<< endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
