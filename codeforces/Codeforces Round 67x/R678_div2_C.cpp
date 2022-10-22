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


#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

#define mod 1000000007

void solve() {
    int n, x, p;
    cin >> n >> x >> p;

    int s = 0, e = n, a = 0, b = 0;
    while (s < e) {
        int m = (s + e) / 2;
        if (m <= p) {
            s = m + 1;
            if (m != p)a++;
        } else e = m, b++;
    }

    ll r = 1;
    for (int i = 0; i < a; i++) r = (r * (x - 1 - i)) % mod;
    for (int i = 0; i < b; i++) r = (r * (n - x - i)) % mod;
    for (int i = 2; i < n - a - b; i++) r = (r * i) % mod;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
