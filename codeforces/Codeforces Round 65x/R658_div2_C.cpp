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
    string a, b;
    cin >> n >> a >> b;

    vi v;
    for (int i = n - 1, s = 0, e = n - 1, st = 0; i >= 0; i--) {
        int x = (a[e] - '0') ^ st;
        int z = (a[s] - '0') ^ st;
        int y = (b[i] - '0');

        if (x != y) {
            if (z == y)v.pb(1);
            v.pb(i + 1);
            if(st % 2) s --;
            else s ++;
            swap(s, e);
            st ^= 1;
        } else {
            if(st % 2) e ++;
            else e --;
        }
    }
    cout << v.size() << " ";
    for (int x: v)cout << x << " ";
    cout << endl;
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
