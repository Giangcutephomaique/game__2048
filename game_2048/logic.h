#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>

class Game2048 {
public:
    Game2048() {
        khoiTaoLaiBang();
    }

    void sinhSoMoi() {
        std::vector<std::pair<int,int>> empty;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (board[i][j] == 0)
                    empty.push_back({i,j});
        if (empty.empty()) return;
        int idx = rand() % static_cast<int>(empty.size());
        int x = empty[idx].first;
        int y = empty[idx].second;
        board[x][y] = (rand() % 2 + 1) * 2; // 2 or 4
    }

    void khoiTaoLaiBang() {
        score = 0;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                board[i][j] = 0;
    }

    int layGiaTriTaiO(int hang, int cot) const {
        if (hang < 0 || hang >= 4 || cot < 0 || cot >= 4) return 0;
        return board[hang][cot];
    }

    int layDiemSo() const {
        return score;
    }

    bool diChuyenTrai() {
        return moveLeft();
    }
    bool diChuyenPhai() {
        rotate(); rotate();
        bool changed = moveLeft();
        rotate(); rotate();
        return changed;
    }
    bool diChuyenLen() {
        rotate(); rotate(); rotate();
        bool changed = moveLeft();
        rotate();
        return changed;
    }
    bool diChuyenXuong() {
        rotate();
        bool changed = moveLeft();
        rotate(); rotate(); rotate();
        return changed;
    }

    bool kiemTraCoTheDiChuyen() const {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (board[i][j] == 0)
                    return true;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == board[i][j+1])
                    return true;
        for (int j = 0; j < 4; ++j)
            for (int i = 0; i < 3; ++i)
                if (board[i][j] == board[i+1][j])
                    return true;
        return false;
    }

private:
    int board[4][4];
    int score;

    bool moveLeft() {
        bool changed = false;
        for (int i = 0; i < 4; ++i) {
            std::vector<int> row;
            for (int j = 0; j < 4; ++j)
                if (board[i][j] != 0)
                    row.push_back(board[i][j]);
            for (size_t j = 0; j + 1 < row.size(); ++j) {
                if (row[j] == row[j+1]) {
                    row[j] *= 2;
                    score += row[j];
                    row[j+1] = 0;
                }
            }
            std::vector<int> newRow;
            for (int x : row)
                if (x != 0) newRow.push_back(x);
            while (newRow.size() < 4) newRow.push_back(0);
            for (int j = 0; j < 4; ++j) {
                if (board[i][j] != newRow[j]) changed = true;
                board[i][j] = newRow[j];
            }
        }
        return changed;
    }

    void rotate() {
        int tmp[4][4];
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                tmp[j][3 - i] = board[i][j];
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                board[i][j] = tmp[i][j];
    }
};
