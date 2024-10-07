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
    int n, t, a, b, da, db;
    cin >> n >> t >> a >> b >> da >> db;
    if (n == 0) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < t; i++)
        for (int j = 0; j < t; j++) {
            if (a - da * i + b - db * j == n || a - da * i == n || b - db * j == n) {
                cout << "YES";
                return;
            }
        }
    cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
