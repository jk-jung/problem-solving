class SCC {
public:
    int n, ord, scc_id;
    vector<vector<int>> *v, scc;
    vector<int> order, node2scc;
    stack<int> st;

    void init(vector<vector<int>> &_v) {
        v = &_v;
        n = (int) v->size();
        ord = scc_id = 0;

        scc.clear();
        order.clear(), order.resize(n, -1);
        node2scc.clear(), node2scc.resize(n, -1);
        while (!st.empty())st.pop();

        for (int i = 0; i < n; i++) {
            if (order[i] != -1) continue;
            dfs(i);
        }
    }

    int dfs(int x) {
        order[x] = ord++;
        st.push(x);

        int parent = order[x];
        for (int y : (*v)[x]) {
            if (order[y] == -1) parent = min(parent, dfs(y));
            else if (node2scc[y] == -1) parent = min(parent, order[y]);
        }

        if (parent == order[x]) {
            vector<int> nodes;
            while (true) {
                int y = st.top();
                st.pop();
                node2scc[y] = scc_id;
                nodes.pb(y);
                if (y == x)break;
            }
            scc.pb(nodes);
            scc_id++;
        }

        return parent;
    }
};