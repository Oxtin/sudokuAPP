#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;

int solve(char[][9], int);

void solveSudoku(char board[9][9]) {
	int solvable = solve(board, 0);
	if (!solvable)
		cout << "cannot solved!\n";
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

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // random seed
	shuffle (arr, arr + 9, std::default_random_engine(seed)); // suffle the array

	for (int i = 0; i < 9; i++) {
		if (used[arr[i]])
			continue;
		Map[r][c] = arr[i] + '0';
		cout << "put " << arr[i] << " at r = " << r << " , c = " << c << '\n';
		if (solve(Map, index + 1))
			return 1;
	}
	Map[r][c] = '.';
	return 0;
}

int main() {
	char board[9][9];

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];

	solveSudoku(board);
	return 0;
}
