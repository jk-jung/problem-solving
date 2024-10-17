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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int r = 0;
    for (int i = 0; i <= 4000; i++)
        for (int j = 0; j <= 4000; j++) {
            int rest = n - a * i - b * j;
            if (rest >= 0 && rest % c == 0)
                r = max(r, i + j + rest / c);
        }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
