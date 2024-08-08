#include <iostream>
using namespace std;

// Hàm tìm kiếm nhị phân
int Binary_Search(int A[], int n, int key) {
	int left = 0;          // Vị trí phần tử đầu tiên trong mảng
	int right = n - 1;     // Vị trí phần tử cuối cùng trong mảng

	while (left <= right) {
		int mid = left + (right - left) / 2;  // Vị trí giữa mảng

		if (A[mid] == key) {
			return mid;  // Trả về chỉ số của phần tử tìm thấy
		}
		if (key < A[mid]) {
			right = mid - 1;  // Tìm kiếm trong nửa trái
		}
		else {
			left = mid + 1;   // Tìm kiếm trong nửa phải
		}
	}
	return -1;  // Không tìm thấy key trong mảng, trả về -1
}

// Hàm main để kiểm tra hàm tìm kiếm nhị phân
int main() {
	// Khởi tạo mảng đã được sắp xếp
	int A[] = {3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(A) / sizeof(A[0]);  // Số phần tử trong mảng

	// Phần tử cần tìm
	int key = 8;
	int result = Binary_Search(A, n, key);

	if (result != -1) {
		cout << "Phần tử " << key << " tìm thấy tại vị trí: " << result << endl;
	}
	else {
		cout << "Phần tử " << key << " không tìm thấy trong mảng." << endl;
	}

	return 0;
}
