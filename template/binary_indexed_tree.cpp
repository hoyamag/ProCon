// Ant book p161
//

// [1, n]
int bit[MAX_N + 1], n;
int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
