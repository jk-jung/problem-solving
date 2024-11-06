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
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    for (int a = 1; a < 10; a++)
        for (int b = 1; b < 10; b++)
            for (int c = 1; c < 10; c++)
                for (int d = 1; d < 10; d++) {
                    if (a == b)continue;
                    if (a == c)continue;
                    if (a == d)continue;
                    if (b == c)continue;
                    if (b == d)continue;
                    if (c == d)continue;
                    if (a + b != r1 || c + d != r2) continue;
                    if (a + c != c1 || b + d != c2)continue;
                    if (a + d != d1 || b + c != d2)continue;
                    cout << a << " " << b << "\n" << c << " " << d << endl;
                    return;
                }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
