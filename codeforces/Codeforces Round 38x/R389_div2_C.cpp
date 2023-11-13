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
    set<char> c;
    int r = 1;
    for(char x: s) {
        if(x == 'L' && c.count('R')) c.clear(), r++;
        if(x == 'R' && c.count('L')) c.clear(), r++;
        if(x == 'U' && c.count('D')) c.clear(), r++;
        if(x == 'D' && c.count('U')) c.clear(), r++;

        c.insert(x);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
