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
    int a, b, t, d;
    cin >> a >> b >> t >> d;
    int r = a;
    for (int i = 1; i < t; i++) {
        int k = t - i - 1;

        int bb = 0;
        for (int j = -d; j <= d; j++) {
            if (a + j >= 0 && ab(a + j - b) <= d * k)bb = j;
        }
        a += bb;
        r += a;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
