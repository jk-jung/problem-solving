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


int n, a, b, r = 0;

void f(int c) {
    if (a < b)swap(a, b);
    while (c--) {
        if (a) {
            a--;
            r++;
        }
        swap(a, b);
    }
}

void solve() {
    int c = 0;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    s += '*';
    for (char x: s) {
        if (x == '.') c++;
        else {
            f(c);
            c = 0;
        }
    }
    f(c);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
