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
    vector<pair<string, string>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (auto &x: v)if (x.S == "rat") cout << x.F << endl;
    for (auto &x: v)if (x.S == "woman" || x.S == "child") cout << x.F << endl;
    for (auto &x: v)if (x.S == "man") cout << x.F << endl;
    for (auto &x: v)if (x.S == "captain") cout << x.F << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
