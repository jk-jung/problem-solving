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
    map<int, int> ck;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (ck.count(b)) ck[b] = min(ck[b], a);
        else ck[b] = a;
    }
    int r = 1 << 30;
    if (ck.count(11)) r = ck[11];
    if (ck.count(1) && ck.count(10)) r = min(r, ck[1] + ck[10]);
    if (r == (1 << 30))r = -1;
    cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
