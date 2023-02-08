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
    string s, r;
    cin >> s;
    queue<char> a, b;
    for (char x: s)
        if ((x - '0') % 2)a.push(x);
        else b.push(x);

    while (!a.empty() || !b.empty()) {
        if (!a.empty() && !b.empty()) {
            if (a.front() < b.front()) {
                r += a.front();
                a.pop();
            } else {
                r += b.front();
                b.pop();
            }
        } else if (!a.empty()) {
            r += a.front();
            a.pop();
        } else {
            r += b.front();
            b.pop();
        }
    }
    cout << r << endl;
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
