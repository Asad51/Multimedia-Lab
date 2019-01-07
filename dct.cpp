#include <bits/stdc++.h> 
using namespace std; 

#define pi 3.142857 
#define sz 8

/**
 * Formula : 
 * dct[i][j] = ci * cj (sum(k=0 to m-1) sum(l=0 to n-1) matrix[k][l] * cos((2*k+1) *i*pi/2*m) * cos((2*l+1) *j*pi/2*n)
 * where ci= 1/sqrt(m) if i=0 else ci= sqrt(2)/sqrt(m) and
 * similarly, cj= 1/sqrt(n) if j=0 else cj= sqrt(2)/sqrt(n)
 */

int dctTransform(int matrix[][sz]) 
{ 
	int i, j, k, l; 

	float dct[sz][sz]; 

	float ci, cj, dct1, sum; 

	for (i = 0; i < sz; i++) { 
		for (j = 0; j < sz; j++) { 

			if (i == 0) 
				ci = 1 / sqrt(sz); 
			else
				ci = sqrt(2) / sqrt(sz); 
			if (j == 0) 
				cj = 1 / sqrt(sz); 
			else
				cj = sqrt(2) / sqrt(sz); 

			// sum will temporarily store the sum of 
			// cosine signals 
			sum = 0; 
			for (k = 0; k < sz; k++) { 
				for (l = 0; l < sz; l++) { 
					dct1 = matrix[k][l] * 
						cos((2 * k + 1) * i * pi / (2 * sz)) * 
						cos((2 * l + 1) * j * pi / (2 * sz)); 
					sum = sum + dct1; 
				} 
			} 
			dct[i][j] = ci * cj * sum; 
		} 
	} 

	for (i = 0; i < sz; i++) { 
		for (j = 0; j < sz; j++) { 
			printf("%f\t", dct[i][j]); 
		} 
		printf("\n"); 
	} 
} 

int main() 
{ 
	int matrix[sz][sz];
	for(int i=0; i<sz; i++){
		for(int j=0; j<sz; j++){
			int a = rand() % 256;
			matrix[i][j] = 255;
		}
	}
	dctTransform(matrix); 
	return 0; 
} 
