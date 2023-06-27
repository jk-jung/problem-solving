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
    string s, a, b;
    map<char, int> ck;
    cin >> s;
    for (char x: s)ck[x]++;
    for (char x = 'a'; x <= 'z'; x++) {
        int t = ck[x] / 2;
        a += string(t, x);
        b += string(t, x);
        ck[x] -= 2 * t;
        if (ck[x] == 1)break;
        ck.erase(x);
    }
    if (ck.empty());
    else if (ck.size() == 1) a += ck.begin()->F;
    else if (ck.size() == 2) {
        auto [x, y] = *ck.rbegin();
        b += string(y / 2, x) + ck.begin()->F;
        a += string((y + 1) / 2, x);
    } else {
        b += ck.begin()->F;
        ck.begin()->S--;
        for (char x = 'a'; x <= 'z'; x++) {
            a += string(ck[x], x);
        }
    }
    reverse(b.begin(), b.end());
    cout << a + b << endl;
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
