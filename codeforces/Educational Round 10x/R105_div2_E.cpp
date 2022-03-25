#include <string.h>
#include <stdio.h>
#include <math.h>
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

map<pi, pair<char, char>> ck;
int xy = 0, xx = 0;

void check(pair<char, char> x, int st) {
    auto[a, b] =  x;
    if (a == 0 || b == 0)return;
    if (a == b)xx += st;
    else xy += st;
}

void solve() {
    int n, m;

    cin >> n >> m;

    while (m--) {
        char op, c;
        int a, b;
        cin >> op;
        if (op == '?') {
            cin >> a;

            if(xx) {
                cout <<"YES\n";
            }
            else if(xy && a % 2 == 1) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        } else if (op == '+') {
            cin >> a >> b >> c;

            pi k = {min(a, b), max(a, b)};

            check(ck[k], -1);
            if (a < b)ck[k].F = c;
            else ck[k].S = c;
            check(ck[k], +1);
        } else {
            cin >> a >> b;

            pi k = {min(a, b), max(a, b)};

            check(ck[k], -1);
            if (a < b)ck[k].F = 0;
            else ck[k].S = 0;
            check(ck[k], +1);
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
