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

bool ok(int x) { return (x & (x + 1)) == 0; }

void solve() {
    int n;
    cin >> n;
    vi v;

    while (!ok(n)) {
        for (int i = 0; i < 30; i++)
            if (n >> i & 1) {
                n = n ^ ((1 << i) - 1);
                v.pb(i);
                if(ok(n))break;
                n++;
                v.pb(0);
            }
    }

    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i += 2) {
        cout << v[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
