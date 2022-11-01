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
    int n, k;
    string a, b;
    map<char, int> c, d;
    cin >> n >> k >> a >> b;
    for (char x: a)c[x]++;
    for (char x: b)d[x]++;

    for (char i = 'a'; i <= 'z'; i++) {
        int x = c[i] - d[i];

        if (x < 0 || x % k) {
            cout << "No\n";
            return;
        } else {
            c[i + 1] += x - x % k;
        }
    }
    cout << "Yes\n";
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
