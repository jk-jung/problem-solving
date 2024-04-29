#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


void solve() {
    string s;
    cin >> s;
    string r;
    r += s[0];
    if(s.size() >= 2)
        r += s[1];
    for(int i=2;i<s.size();i++){
        if(s[i] == r[r.size()-1] && r[r.size()-1] == r[r.size()-2])continue;
        if(r.size() >= 3 && s[i] == r[r.size()-1] && r[r.size()-2] == r[r.size()-3])continue;
        r += s[i];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
