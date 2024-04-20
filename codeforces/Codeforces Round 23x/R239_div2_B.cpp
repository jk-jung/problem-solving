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
    string a;
    string b;
    cin >> a >> b;
    map<char, int> c;
    for(char x:a)c[x]++;
    int r = 0;
    for(char x: b) {
        if(c.count(x)){
            if(c[x] > 0) {
                c[x]--;
                r++;
            }
        }
        else {
            cout << -1;
            return;
        }
    }
    cout << r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
