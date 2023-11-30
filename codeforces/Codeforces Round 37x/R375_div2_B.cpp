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
    int a = 0, b = 0;
    int n;
    string s, cur;
    cin >> n >> s;
    bool flag = false;
    s += '_';
    for (char x: s) {
        if (x == '(') {
            flag = true;
            a = max(a, (int) cur.size());
            cur = "";
        } else if (x == ')') {
            flag = false;
            if (!cur.empty())b++;
            cur = "";
        } else if (x == '_') {
            if (flag) {
                if (!cur.empty()) b++;
            } else {
                a = max(a, (int) cur.size());
            }
            cur = "";
        } else cur += x;
    }
    cout << a << " " << b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
