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
    int r = 0, c = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        string o;
        int x;
        cin >> o >> x;
        if (o == "+") {
            c++;
            s.insert(x);
        } else {
            if (s.count(x)) {
                c--;
                s.erase(x);
            } else {
                r++;
            }
        }
        r = max(r, c);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
