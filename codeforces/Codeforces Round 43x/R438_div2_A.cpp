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
    cin >> a;
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &x: v)cin >> x;
    for (auto x: v)
        for (auto &y: v) {
            string z = x + y;
            if (z.find(a) != string::npos) {
                cout << "YES\n";
                return;
            }
        }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}