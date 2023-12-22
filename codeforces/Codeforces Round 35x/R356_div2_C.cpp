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

vi p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool q(int x) {
    cout << x << endl;
    string r;
    cin >> r;
    return r[0] == 'y';
}

void solve() {
    vi v;
    for (int x: p) {
        if (q(x)) v.pb(x);
    }
    if (v.empty())cout << "prime" << endl;
    else if (v.size() == 1) {
        if (v[0] * v[0] > 100 || !q(v[0] * v[0]))cout << "prime" << endl;
        else cout << "composite" << endl;
    } else cout << "composite" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
