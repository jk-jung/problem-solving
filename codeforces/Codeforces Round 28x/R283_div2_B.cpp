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
    string s;
    cin >> n >> s;
    vector<string> v;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n; j++) {
            v.pb(s);
            s = s.substr(1) + s[0];
        }
        for (char &x: s) {
            if (++x > '9')x = '0';
        }
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
