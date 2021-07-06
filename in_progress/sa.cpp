#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp    make_pair
#define pb    push_back
#define ab(x) (((x)<0)?-(x):(x))

class SuffixArray {
    string s;

    SuffixArray(string &t) {
        s = t;
        s += '$'

        int n = s.size();
        int prev = 0, next = 1;

        vector<int> ord[2];

        ord[0].resize(n);
        ord[1].resize(n);

        for (int k = 1, cur = 0;; k *= 2, cur ^= 1) {
            for (int i = 0; i < n; i++) {
                if (k == 1) ord[cur] = s[i];
                else {

                }
            }
            sort(ord[cur].begin(), ord[cur].end());
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

}
