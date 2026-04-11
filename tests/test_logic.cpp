/*
 * Mục đích: Test logic game 2048.
 * Chức năng: Kiểm tra các hàm xử lý logic có hoạt động đúng không.
 */

#include "../src/logic.h"
#include <iostream>

using namespace std;

/*
 * Mục đích: Hiển thị bảng 4x4 ra console để kiểm tra.
 * Logic xử lý: Duyệt từng ô trong bảng, in giá trị ra màn hình.
 */
void inBang() {
  // Duyệt từng ô trong bảng 4x4 và in giá trị
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << bang_o[i][j] << "\t";
    }
    cout << endl;
  }
  cout << "-------------" << endl;
}

/*
 * Mục đích: Kiểm tra hàm sinhSoMoi() có sinh đúng 2 số vào bảng trống không.
 * Logic xử lý: Khởi tạo lại bảng, gọi sinhSoMoi() 2 lần, đếm số ô khác 0 phải
 * bằng 2.
 */
bool testSinhHaiSoMoi() {
  khoiTaoLaiBang();

  cout << "Bang truoc khi sinh so:" << endl;
  inBang();

  sinhSoMoi();
  sinhSoMoi();

  cout << "Bang sau khi sinh 2 so ngau nhien:" << endl;
  inBang();

  int dem_o_co_so = 0;

  // Đếm số ô có giá trị khác 0
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (bang_o[i][j] != 0) {
        dem_o_co_so++;
      }
    }
  }

  if (dem_o_co_so == 2) {
    return true;
  }
  return false;
}

/*
 * Mục đích: Chạy tất cả test case.
 * Logic xử lý: Gọi từng hàm test, in kết quả PASSED hoặc FAILED.
 */
int main() {
  cout << "Bat dau chay Unit Test:" << endl;

  bool ket_qua = testSinhHaiSoMoi();
  if (ket_qua) {
    cout << "Test 1 - Kiem tra ham sinh so ngau nhien: PASSED." << endl;
  } else {
    cout << "Test 1 - Kiem tra ham sinh so ngau nhien: FAILED." << endl;
  }

  return 0;
}
