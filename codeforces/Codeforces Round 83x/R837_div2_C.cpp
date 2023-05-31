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

const int MAX = 100005;
vi p;

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    set<int> ck, c2;
    for (int &x: v) {
        for (int y: p) {
            if (x % y == 0) {
                if (ck.count(y)) {
                    cout << "YES\n";
                    return;
                }
                ck.insert(y);
            }
            while (x % y == 0)x /= y;
        }
        if(x > 1 && c2.count(x)){
            cout << "YES\n";
            return;
        }
        c2.insert(x);
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> prime(MAX + 1);
    for (int i = 2; i <= MAX; i++) {
        if (prime[i])continue;
        p.pb(i);
        for (int j = i + i; j <= MAX; j += i) prime[j] = i;
    }


    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
