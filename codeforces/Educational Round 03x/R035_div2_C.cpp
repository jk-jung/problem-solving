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
    vi v(3);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    if (v[0] == 1) {
        cout << "YES";
    } else if (v[0] == 2) {
        if (v[1] == 2)cout << "YES";
        else if(v[1] == 4 && v[2] == 4)cout << "YES";
        else cout << "NO";
    } else if(v[0] == 3 && v[2]== 3){
        cout << "YES";
    }else {
        cout << "NO";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
