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
    int n;
    cin >> n;
    vi v(n), a, b;
    ll A =0 , B =0;
    for (int &x: v) {
        cin >> x;
        if (x < 0)b.pb(-x), B += -x;
        else a.pb(x), A += x;
    }
    if(A == B) {
        if(a == b) {
            cout << (v.back() > 0 ? "first" : "second");
        }
        else if(a > b)cout << "first";
        else cout << "second";
    }else {
        if(A > B)cout << "first";
        else cout << "second";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
