#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<cuda.h>
#include <device_launch_parameters.h>
#include <cuda_runtime_api.h>

__global__ void even(int *darr, int n) {
	int k = threadIdx.x;
	int t;
	k = k * 2;
	if (k <= n - 2) {
		if (darr[k] > darr[k + 1]) {
			t = darr[k];
			darr[k] = darr[k + 1];
			darr[k + 1] = t;
		}
	}
}

__global__ void odd(int *darr, int n) {
	int k = threadIdx.x;
	int t;
	k = k * 2 + 1;
	if (k <= n - 2) {
		if (darr[k] > darr[k + 1]) {
			t = darr[k];
			darr[k] = darr[k + 1];
			darr[k + 1] = t;
		}
	}

}

void main() {
	int *arr, *darr;
	int n = 200, i;
	arr = (int*)malloc(n * sizeof(int));
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		arr[i] = rand() % 500;
	}
	
	cudaMalloc(&darr, n * sizeof(int));
	cudaMemcpy(darr, arr, n * sizeof(int), cudaMemcpyHostToDevice);
	for (i = 0; i <= n / 2; i++) {
		even << <1, n >> >(darr, n);
		odd << <1, n >> >(darr, n);
	}
	cudaMemcpy(arr, darr, n * sizeof(int), cudaMemcpyDeviceToHost);
	cudaFree(darr);
	printf("Sorted array: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	getch();
}