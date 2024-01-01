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

bool solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;

    map<ll, int> a[2];
    a[0][0] = a[1][0] = 1;
    vector<ll> s(2);
    for (int i = 1; i < n; i++) {
        int x = i % 2;
        s[x] += v[i] - v[i - 1];
        if (a[x].count(s[x])) return true;
        if (i + 1 < n && a[x].count(s[x] - v[i + 1]))return true;
        a[x][s[x]]++;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        cout << (solve() ? "YES" : "NO") << endl;
}
