#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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

int p[1111];
map<string, int> ck;

void solve() {
    int n;
    string s, r, t;
    cin >> n >> s;
    r = s;
    for (int i = 0; i < n; i++) {
        t += s[i];
        if(p[stoi(t)] && r.length() > t.length()) r = t;
        for (int j = i + 1; j < n; j++) {
            t += s[j];
            if(p[stoi(t)] && r.length() > t.length()) r = t;
            for (int k = j + 1; k < n; k++) {
                t += s[k];
                if(p[stoi(t)] && r.length() > t.length()) r = t;
                t.pop_back();
            }
            t.pop_back();
        }
        t.pop_back();
    }
    cout << r.size() <<'\n';
    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    p[1] = 1;
    for(int i= 2;i<1000;i++){
        if(p[i]) continue;

        for(int j=i+i;j<1000;j+=i)p[j] = 1;
    }

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
