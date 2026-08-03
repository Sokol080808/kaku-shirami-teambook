/**
 * Author: alexxela12345
 * Date: 2024-09-11
 * Description: dealing with planar graphs
 */

// returns faces.size(), if v in the outter face
int find_face(const vector<vec> &pts, const vector<vector<int>> &faces, vec v) {
    int res = faces.size();
    ld resarea = 0;
    vector<vec> face;
    for (int i = 0; i < (int)faces.size(); ++i) {
        face.clear();
        for (int j : faces[i]) {
            face.push_back(pts[j]);
        }
        ld area = get_area(face);
        if (sign(area) > 0) {
            if (isIn(face, v)) {
                // return faces.size(); // if faces are connected
                if (res == (int)faces.size() || area < resarea) {
                    res = i;
                    resarea = area;
                }
            }
        }
    }
    return res;
}

// g.size()==pts.size()+1, so that there is one new outter face
// all previously outter faces will have g[v].size()==0
vector<vector<int>> build_faces_graph(const vector<vec> &pts, const vector<vector<int>> &faces) {
    vector<int> realface(faces.size());
    iota(all(realface), 0);
    vector<vec> qq;
    vector<int> ind;
    for (int i = 0; i < (int) faces.size(); ++i) {
        vector<vec> face;
        for (int j : faces[i]) {
            face.pbc(pts[j]);
        }
        ld a = get_area(face);
        if (a < 0) {
            // if only one outter face, then realface[i] = faces.size(); otherwise following code
            vec v = *min_element(all(face));
            v.x -= 10 * EPS;
            qq.pbc(v);
            ind.pbc(i);
            // realface[i] = find_face(pts, faces, v);
            // assert(realface[i] != i);
        }
    }
    if (1) { // slow, but easy to write
        for (int i = 0; i < (int)qq.size(); ++i) {
            int j = find_face(pts, faces, qq[i]);
            assert(j != ind[i]);
            realface[ind[i]] = j;
        }
    } else {
        vector<int> res = point_location(pts, faces, qq);
        for (int i = 0; i < (int)qq.size(); ++i) {
            int j = res[i];
            assert(j != ind[i]);
            realface[ind[i]] = j;
        }
    }
    map<pair<int, int>, int> edge2face;
    for (int i = 0; i < (int) faces.size(); ++i) {
        for (int j = 0; j < (int) faces[i].size(); ++j) {
            int a = faces[i][j];
            int b = faces[i][(j + 1) % faces[i].size()];
            edge2face[{a, b}] = realface[i];
        }
    }
    vector<vector<int>> g(faces.size() + 1);
    for (auto [pp, c] : edge2face) {
        g[c].pbc(edge2face[{pp.second, pp.first}]);
    }
    for (auto &el : g) {
        sort(all(el));
        el.erase(unique(all(el)), el.end());
    }
    return g;
}

vector<vector<int>> get_faces(const vector<vec> &pts, const vector<vector<int>> &g) {
    int n = g.size();
    vector<vector<pair<int, int>>> g2(n);
    int cur_edge = 0;
    for (int i = 0; i < n; ++i) {
        for (int j : g[i]) {
            if (i < j) {
                g2[j].pbc({i, cur_edge});
                g2[i].pbc({j, cur_edge ^ 1});
                cur_edge += 2;
            }
        }
    }
    vector<int> ind(cur_edge), used(cur_edge);
    for (int i = 0; i < n; ++i) {
        sort(all(g2[i]), [&](auto a, auto b) {
            auto va = pts[a.first] - pts[i];
            auto vb = pts[b.first] - pts[i];
            return mp(half(va), (ld)0) < mp(half(vb), va % vb);
        });
        for (int j = 0; j < (int) g2[i].size(); ++j) {
            ind[g2[i][j].second] = j;
        }
    }
    vector<vector<int>> faces;
    for (int i = 0; i < n; ++i) {
        for (int ei = 0; ei < (int)g[i].size(); ++ei) {
            if (used[g2[i][ei].second]) continue;
            vector<int> face;
            int v = i;
            int e = g2[v][ei].second;
            while (!used[e]) {
                used[e] = 1;
                face.pbc(v);
                int u = g2[v][ind[e]].first;
                int newe = g2[u][(ind[e ^ 1] - 1 + g2[u].size()) % g2[u].size()].second;
                v = u;
                e = newe;
            }
            faces.push_back(face);
        }
    }
    return faces;
}

pair<vector<vec>, vector<vector<int>>> build_graph(vector<pair<vec, vec>> segs) {
    vector<vec> p;
    vector<vector<int>> g;
    map<pair<ll, ll>, int> id;
    auto getid = [&](vec v) {
        auto r = mp(ll(round(v.x * 1'000'000'000 + EPS * sign(v.x))), ll(round(v.y * 1'000'000'000 + EPS * sign(v.y))));
        if (!id.count(r)) {
            g.pbc({});
            int i = id.size();
            id[r] = i;
            p.pbc(v);
            return i;
        }
        return id[r];
    };
    for (int i = 0; i < (int)segs.size(); ++i) {
        vector<int> cur = {getid(segs[i].first), getid(segs[i].second)};
        for (int j = 0; j < (int)segs.size(); ++j) {
            if (i != j) {
                if (intersects(segs[i].first, segs[i].second, segs[j].first, segs[j].second)) {
                    vec res;
                    if (intersect(getln(segs[i].first, segs[i].second), getln(segs[j].first, segs[j].second), res)) {
                        cur.pbc(getid(res));
                    } else {
                        if (isOnSegment(segs[i].first, segs[i].second, segs[j].first))
                            cur.pbc(getid(segs[j].first));
                        if (isOnSegment(segs[i].first, segs[i].second, segs[j].second))
                            cur.pbc(getid(segs[j].second));
                    }
                }
            }
        }
        sort(all(cur), [&](int i, int j) { return p[i] < p[j]; });
        cur.erase(unique(all(cur)), cur.end());
        for (int j = 1; j < (int)cur.size(); ++j) {
            g[cur[j]].pbc(cur[j - 1]);
            g[cur[j - 1]].pbc(cur[j]);
        }
    }
    for (auto &el : g) {
        sort(all(el));
        el.erase(unique(all(el)), el.end());
    }
    return {p, g};
}