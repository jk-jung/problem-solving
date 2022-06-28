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

int n, m;
string s;
int ck[555];

void solve() {
    cin >> n >> m >> s;
    while (m--) {
        char x;
        cin >> x;
        ck[x] = 1;
    }

    s += 'Z';
    ll r = 0, c = 0;
    for (auto x: s) {
        if (ck[x]) c++;
        else r += c * (c + 1) / 2, c = 0;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
