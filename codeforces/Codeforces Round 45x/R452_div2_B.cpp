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

int t[44] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;


    for (int i = 0; i < 12; i++) {
        bool ok = true, leap = false;
        for (int j = 0; j < n; j++) {
            if (v[j] != t[(i + j) % 12]) {
                if (!leap && v[j] == 29 && (i + j) % 12 == 1) {
                    leap = true;
                } else ok = false;
            }
        }
        if (ok) {
            cout << "Yes\n";
            return;
        }
    }
    cout <<"No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
