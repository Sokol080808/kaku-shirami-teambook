/**
 * Author: Alexey Vasilyev
 * Date: ?
 * Description: matroid interestion
 * Time: ?
 */


template<typename T, typename A, typename B>
vector<T> matroid_intersection(const std::vector<T> &ground_set, const A &matroid1, const B &matroid2) {
    //weighted - minimize (weight, cnt edges) with dijkstra
    int n = ground_set.size();
    vector<char> in_set(n), inm1(n), inm2(n);
    vector<bool> used(n);
    vi par(n), left, right;
    while (true) {
        A m1 = matroid1;
        B m2 = matroid2;
        left.clear(); right.clear();
        for (int i = 0; i < n; i++)
        if (in_set[i]) {
            m1.add(ground_set[i]);
            m2.add(ground_set[i]);
            left.push_back(i);
        } else {
        right.push_back(i);
        }
        fill(all(inm1), 0); fill(all(inm2), 0);
        bool found = false;
        for (int i : right) {
            inm1[i] = m1.independed_with(ground_set[i]);
            inm2[i] = m2.independed_with(ground_set[i]);
            if (inm1[i] && inm2[i]) {
                in_set[i] = 1;
                found = true;
                break;
            }
        }
        if (found) continue;
        fill(all(used), false); fill(all(par), -1);
        queue<int> que;
        for (int i : right) if (inm1[i]) {
            used[i] = true;
            que.push(i);
        }
        while (!que.empty() && !found) {
            int v = que.front();
            que.pop();
            if (in_set[v]) {
                A m = matroid1;
                for (int i : left) if (i != v) m.add(ground_set[i]);
                for (int u : right)
                    if (!used[u] && m.independed_with(ground_set[u])) {
                        par[u] = v;
                        used[u] = true;
                        que.push(u);
                        if (inm2[u]) {
                            found = true;
                            for (; u != -1; u = par[u]) in_set[u] ^= 1;
                            break;
                        }
                    }
            } else {
                    B m = m2;
                    m.add_extra(ground_set[v]);
                    for (auto u : left)
                    if (!used[u] && m.independed_without(ground_set[u])) {
                        par[u] = v;
                        used[u] = true;
                        que.push(u);
                    }
            }
        }
        if (!found) break;
    }
    vector<T> res;
    for (int i = 0; i < n; i++) if (in_set[i]) res.push_back(ground_set[i]);
    return res;
}