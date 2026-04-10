#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int board[4][4];
int score = 0;

// in bảng
void printBoard() {
    system("cls");
    cout << "====== 2048 GAME ======\n";
    cout << "Score: " << score << "\n\n";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) cout << ".\t";
            else cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

// sinh số mới
void addNumber() {
    vector<pair<int, int>> empty;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 0)
                empty.push_back({ i,j });

    if (empty.empty()) return;

    int idx = rand() % empty.size();
    int x = empty[idx].first;
    int y = empty[idx].second;

    board[x][y] = (rand() % 2 + 1) * 2;
}

// move trái (FIX VECTOR)
bool moveLeft() {
    bool changed = false;

    for (int i = 0; i < 4; i++) {
        vector<int> row;

        // lấy số khác 0
        for (int j = 0; j < 4; j++)
            if (board[i][j] != 0)
                row.push_back(board[i][j]);

        // gộp (AN TOÀN)
        for (int j = 0; j + 1 < row.size(); j++) {
            if (row[j] == row[j + 1]) {
                row[j] *= 2;
                score += row[j];
                row[j + 1] = 0;
            }
        }

        // dồn lại
        vector<int> newRow;
        for (int x : row)
            if (x != 0) newRow.push_back(x);

        while (newRow.size() < 4)
            newRow.push_back(0);

        // cập nhật bảng
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != newRow[j])
                changed = true;
            board[i][j] = newRow[j];
        }
    }

    return changed;
}

// xoay ma trận
void rotate() {
    int tmp[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmp[j][3 - i] = board[i][j];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            board[i][j] = tmp[i][j];
}

// các hướng
bool moveRight() {
    rotate(); rotate();
    bool changed = moveLeft();
    rotate(); rotate();
    return changed;
}

bool moveUp() {
    rotate(); rotate(); rotate();
    bool changed = moveLeft();
    rotate();
    return changed;
}

bool moveDown() {
    rotate();
    bool changed = moveLeft();
    rotate(); rotate(); rotate();
    return changed;
}

// kiểm tra còn đi được không
bool canMove() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 0)
                return true;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == board[i][j + 1])
                return true;

    for (int j = 0; j < 4; j++)
        for (int i = 0; i < 3; i++)
            if (board[i][j] == board[i + 1][j])
                return true;

    return false;
}

