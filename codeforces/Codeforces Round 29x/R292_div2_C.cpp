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
    string s;
    cin >> n >> s;

    string r;
    for (char x: s) {
        if (x == '7')r += '7';
        else if (x == '5') r += '5';
        else if (x == '3') r += '3';
        else if (x == '2') r += '2';
        else if (x == '4') r += "322";
        else if (x == '6') r += "35";
        else if (x == '8') r += "2227";
        else if (x == '9') r += "3327";
    }
    sort(r.rbegin(), r.rend());
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
