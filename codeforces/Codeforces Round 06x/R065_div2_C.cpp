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
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    for (int i = 1; i <= n; i++) {
        if (n % i)continue;
        if(n / i < 3)continue;
        for (int o = 0; o < i; o++) {
            bool ok = true;
            for (int k = o; k < n; k += i) {
                if (!v[k]) {
                    ok = false;
                    break;
                }
            }
            if(ok){
                cout << "YES";
                return;
            }

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
