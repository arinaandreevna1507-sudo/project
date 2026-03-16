#include <stdio.h>

	/*const int size = 6;
	int arr[size];
	for (int i = 0; i<size; ++i) {
		arr[i] = i;
	}
	for (int i = 0; i<size; ++i) {
		printf(" %d ", arr[i]);
	}
	for (int i = size-1; i>=0; --i) {
		printf(" %d ", arr[i]);
	}*/

int main() {
	const int height = 4;
	const int width = 6;
	int left = 0;
	int right = width - 1;
	int top = 0;
	int bottom = height - 1;
	int arr[height][width];
	int i = 1;

	int minSide = height;
	if (width < height) {
		minSide = width;
	}

	for (int count = 0; count < minSide / 2; ++count) {
		for (int x = left; x <= right; ++x, ++i) {
			arr[top][x] = i;
		}
		++top;
		for (int y = top; y <= bottom; ++y, ++i) {
			arr[y][right] = i;
		}
		--right;
		for (int x = right; x >= left; --x, ++i) {
			arr[bottom][x] = i;
		}
		--bottom;
		for (int y = bottom; y >= top; --y, ++i) {
			arr[y][left] = i;
		}
		++left;
	}
	if (minSide % 2 != 0) {
		for (int x = left; x <= right; ++x, ++i) {
			arr[top][x] = i;
		}
		++top;
		for (int y = top; y <= bottom; ++y, ++i) {
			arr[y][right] = i;
		}
		--right;
	}
	
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			printf("%d\t", arr[y][x]);
		}
		printf("\n");
	}
	return 0;
}

/*for (int y = 0; y < height; ++y) {
		if (y % 2 ==0) {
			for (int x = 0; x < width; ++x,++i) {
				arr[y][x] = i;
			}
		}
		else {
			for (int x = width-1; x >=0; --x,++i) {
				arr[y][x] = i;
			}
		}

	}*/