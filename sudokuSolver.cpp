#include <iostream>
using namespace std;

int solve(char[][9], int);

void solveSudoku(char board[9][9]) {
	int solvable = solve(board, 0);
	if (!solvable)
		cout << "cannot solved!";
}

int solve(char Map[][9], int index) { // 0 to 80
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << Map[i][j] << ' ';
		cout << '\n';
	}

	if (index == 81)
		return 1;

	int r = index / 9;
	int c = index % 9;
	cout << "r = " << r << ", c = " << c << '\n';

	if (Map[r][c] != '.')
		return solve(Map, index + 1);

	int used[10] = {0};
	int dir[3][2] = {{1, 2}, {-1, 1}, {-2, -1}};

	for (int i = 0; i < 9; i++) {
		if (Map[r][i] != '.')
			used[Map[r][i] - '0'] = 1;
		if (Map[i][c] != '.')
			used[Map[i][c] - '0'] = 1;
	}

	int x = r % 3;
	int y = c % 3;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			char now = Map[r + dir[x][i]][c + dir[y][j]];
			if  (now != '.')
				used[now - '0'] = 1;
		}
	}

	cout << "========== ";
	for (int i = 1; i <= 9; i++)
		cout << used[i] << ' ';
	cout << " ==========\n";

	for (int i = 1; i <= 9; i++) {
		if (used[i])
			continue;
		Map[r][c] = i + '0';
		cout << "put " << i << " at r = " << r << " , c = " << c << '\n';
		if (solve(Map, index + 1))
			return 1;
	}
	Map[r][c] = '.';
	return 0;
}

int main() {
	char board[9][9] = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

	

	solveSudoku(board);
	return 0;
}
