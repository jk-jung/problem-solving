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
    int n, a, b;
    cin >> n >> a >> b;
    vi v(n);
    for (int i = 0; a * i <= n; i++) {
        if ((n - a * i) % b == 0) {
            int x = 0;
            for (int k = 0; k < i; k++) {
                v[k * a + a - 1] = x++;
                for (int j = 0; j < a - 1; j++) {
                    v[k * a + j] = x++;
                }
            }
            int m = (n - a * i) / b;
            for (int k = 0; k < m; k++) {
                v[a * i + k * b + b - 1] = x++;
                for (int j = 0; j < b - 1; j++) {
                    v[a * i + k * b + j] = x++;
                }
            }
            for (int y: v)cout << y + 1<< " ";
            return;
        };
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
