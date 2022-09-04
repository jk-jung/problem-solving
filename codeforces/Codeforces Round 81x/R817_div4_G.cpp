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
    if (n == 3) {
        cout << "2 1 3\n";
        return;
    }
    int m = n / 2;
    vi v;
    for (int i = 1; i <= m; i++) {
        v.pb((i + 10)* 2 + (i % 2 == 0));
        v.pb((i + 10)* 2 + (i % 2 == 1));
    }
    if(m % 2) {
        vi t = {4, 1, 2, 12, 3, 8};
        for(int i=0;i<6;i++)v[i] = t[i];
    }
    if (n % 2)v.pb(0);
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
