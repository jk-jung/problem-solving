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

    vi no(n + 1);
    if (n == 1) {
        cout << s << endl;
        return;
    }
    int a = 0, b = 0;
    for (int k = 0; k < 20; k++) {
        int i = 0;
        for (char x: s) {
            if (!no[i]) {
                if (x == 'D') {
                    if (b)b--, n--, no[i] = 1;
                    else a++;
                } else {
                    if (a)a--, n--, no[i] = 1;
                    else b++;
                }
                if (n == 1) {
                    cout << (x == 'D' ? 'R' : 'D');
                    return;
                }
            }
            i++;
        }
    }
    for(int i=0;i<s.size();i++){
        if(!no[i]){
            cout << s[i] << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
