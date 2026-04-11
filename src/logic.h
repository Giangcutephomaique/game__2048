/*
 * Mục đích: Khai báo biến toàn cục và các hàm xử lý logic game 2048.
 * Chức năng: Khai báo bảng số, điểm và các hàm di chuyển, sinh số, kiểm tra.
 */

#ifndef LOGIC_H
#define LOGIC_H

#include <cstdlib>

extern int bang_o[4][4];
extern int diem_so;

void khoiTaoLaiBang();
void sinhSoMoi();

bool diChuyenTrai();
bool diChuyenPhai();
bool diChuyenLen();
bool diChuyenXuong();

bool kiemTraCoTheDiChuyen();

#endif
