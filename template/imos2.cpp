vector < vector<int>> imos2(vector < vector<int>> mat) {
	//imos2
	// mat = {
	//		0,1,0,2
	//		3,4,1,1
	//		0,3,1,9}
	// return = {
	//		0,1,1,3
	//		3,8,9,12
	//		3,11,13,25}
	// return[i][j] means sum of mat[k][l] ( k = 0~i, l = 0~j)

	int n = mat.size();
	int m = mat[0].size();
	for (int i = 0; i < n; i++)for (int j = 0; j < m-1; j++) mat[i][j + 1] += mat[i][j];
	for (int i = 0; i < n; i++)for (int j = 0; j < m-1; j++) mat[j + 1][i] += mat[j][i];
	return mat;

}
int imos2rectangle(const vector<vector<int>>&imos2table, int xl, int yl, int xr, int yr) {
	// a sum of the numbers included in a rectangle area of original table; rectangle area, between xl and xr, yl and yr.
	// imos2table indicates sum of originalTable[k][l] ( k = 0~i, l = 0~j)
		// imos2table = {// should be produced by function "imos2"
		//		0,1,1,3
		//		3,8,9,12
		//		3,11,13,25
		//		3,11,13,25}
		// xl = 1, yl =0, xr = 3, yr = 2
		// return = 12

	int n = imos2table.size();
	int m = imos2table[0].size();
	if (xl > xr || yl > yr) return 0;
	bool fxl = xl - 1 >= 0;
	bool fyl = yl - 1 >= 0;
	int left = fyl ? imos2table[xr][yl - 1] : 0;
	int up = fxl ? imos2table[xl - 1][yr] : 0;
	int corner = fxl&&fyl ? imos2table[xl - 1][yl - 1] : 0;
	int body = imos2table[xr][yr];
	return body - left - up + corner;
}
