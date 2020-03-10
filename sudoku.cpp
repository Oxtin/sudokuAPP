#include <iostream>
using namespace std

void solveSudoku(vector<vector<char>>& board) {
	int map[11][11] = {0};

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			map[i + 1][j + 1] = board[i][j];

	
}

void solve(int map[][11], int index) { // 0 to 80
	int r = index / 9 + 1;
	int c = index % 9 + 1;

	if (map[r][c] == '.') {
		solve(map, index + 1);
		return;
	}

	int used[10] = {0};
	int dir[10][2] = {{0, 0}, {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

	for (int i = 1; i <= 9; i++) {
		if (map[r][i] != '.')
			used[map[r][i] - '0'] = 1;
		if (map[i][c] != '.')
			used[map[i][c] - '0'] = 1;
		if (map[r + dir[i][0]][c + dir[i][1]] != '.')
			used[map[r + dir[i][0]][c + dir[i][1]] - '0'] = 1;
	}

	for (int i = 1; i <= 9, !used[i]; i++) {
		map[r][c] = i;
		solve(map, index + 1);
	}
	return;
}

int main() {
	
}
