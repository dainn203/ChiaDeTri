#include <stdio.h>
#include <stdlib.h>

// Định nghĩa Big_Int sử dụng kiểu unsigned long long cho ví dụ
typedef unsigned long long Big_Int;

// Hàm để lấy n chữ số đầu của số
Big_Int left(Big_Int X, int n) {
	Big_Int divisor = 1;
	for (int i = 0; i < n; i++) {
		divisor *= 10;
	}
	return X / divisor;
}

// Hàm để lấy n chữ số cuối của số
Big_Int right(Big_Int X, int n) {
	Big_Int divisor = 1;
	for (int i = 0; i < n; i++) {
		divisor *= 10;
	}
	return X % divisor;
}

// Hàm nhân hai số lớn theo thuật toán Karatsuba
Big_Int Big_Number_Multi(Big_Int X, Big_Int Y, int n) {
	if (n == 1) { // X, Y có 1 chữ số
		return X * Y;
	}
	else {
		int half_n = n / 2;

		// Chia X và Y thành các phần
		Big_Int A = left(X, half_n);
		Big_Int B = right(X, half_n);
		Big_Int C = left(Y, half_n);
		Big_Int D = right(Y, half_n);

		// Đệ quy nhân các phần
		Big_Int m1 = Big_Number_Multi(A, C, half_n);
		Big_Int m2 = Big_Number_Multi(A + B, C + D, half_n);
		Big_Int m3 = Big_Number_Multi(B, D, half_n);

		// Kết hợp kết quả
		Big_Int pow10_half_n = 1;
		Big_Int pow10_n = 1;
		for (int i = 0; i < half_n; i++) {
			pow10_half_n *= 10;
		}
		for (int i = 0; i < n; i++) {
			pow10_n *= 10;
		}

		return m1 * pow10_n + (m2 - m1 - m3) * pow10_half_n + m3;
	}
}

int main() {
	Big_Int X = 1234567890123456789ULL;
	Big_Int Y = 9876543210987654321ULL;
	int n = 18; // Số chữ số của X và Y

	Big_Int result = Big_Number_Multi(X, Y, n);
	printf("Ket qua: %llu\n", result);

	return 0;
}
