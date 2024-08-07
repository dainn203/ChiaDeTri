#include <stdio.h>
#include <stdlib.h>

// Hàm trộn hai nửa của mảng A
void Merge(int A[], int left, int mid, int right) {
	int n1 = mid - left + 1; // Độ dài nửa đầu của mảng
	int n2 = right - mid;    // Độ dài nửa sau của mảng

	// Tạo các mảng tạm thời để lưu nửa đầu và nửa sau của mảng
	int *L = (int *)malloc(n1 * sizeof(int));
	int *R = (int *)malloc(n2 * sizeof(int));

	// Chép dữ liệu vào các mảng tạm thời L và R
	for (int i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = A[mid + 1 + j];
	}

	// Trộn các mảng tạm thời L và R lại vào mảng A
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}

	// Chép các phần tử còn lại của L vào A nếu có
	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}

	// Chép các phần tử còn lại của R vào A nếu có
	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}

	// Giải phóng bộ nhớ tạm thời
	free(L);
	free(R);
}

// Hàm Merge Sort chia mảng và sắp xếp các phần tử
void Merge_Sort(int A[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		// Gọi đệ quy để sắp xếp nửa đầu và nửa sau
		Merge_Sort(A, left, mid);
		Merge_Sort(A, mid + 1, right);

		// Trộn hai nửa đã sắp xếp
		Merge(A, left, mid, right);
	}
}

// Hàm chính để kiểm tra Merge Sort
int main() {
	int A[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(A) / sizeof(A[0]);

	printf("Given array is \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	Merge_Sort(A, 0, n - 1);

	printf("\nSorted array is \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}
