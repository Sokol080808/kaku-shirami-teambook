/**
 * Author: Iurii Pustovalov
 * Date: 2024-09-09
 * Description: Determinant in ld
 */

double det(vector<vector<double>>& a) {
  int n = sz(a);
  double res = 1;
  for (int i = 0; i < n; ++i) {
    int b = i;
    for (int j = i + 1; j < n; ++j)
      if (fabs(a[j][i]) > fabs(a[b][i])) b = j;
    if (i != b) swap(a[i], a[b]), res *= -1;
    res *= a[i][i];
    if (res == 0) return 0;
    for (int j = i + 1; j < n; ++j) {
      double v = a[j][i] / a[i][i];
      if (v != 0)
        for (int k = i + 1; k < n; ++k) a[j][k] -= v * a[i][k];
    }
  }
  return res;
}