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
    string a, b;
    cin >> a >> b;
    a += '.';
    b += '.';
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != '0') {
            a = a.substr(i);
            break;
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] != '0') {
            b = b.substr(i);
            break;
        }
    }

    if (a == b)cout << '=';
    else if(a.size() == b.size())cout << (a < b ? '<' : '>');
    else cout << (a.size() < b.size() ? '<' : '>');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
