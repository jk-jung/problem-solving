
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
    string a;
    string b;
    cin>>a>>b;
    vi c(b.size() + 2), d(b.size() + 2);
    for (int i = 1; i <= b.size(); i++)
        c[i] = c[i - 1] + (b[i - 1] == '1'), d[i] = d[i - 1] + (b[i - 1] == '0');

    ll r = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '0')r += c[b.size() - a.size() + i + 1] - c[i];
        else r += d[b.size() - a.size() + i + 1] - d[i];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
