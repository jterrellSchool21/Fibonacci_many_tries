#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>

unsigned long long	fib_recur(int N){
	if(N == 1 || N == 2){
		return 1;
	}
	return fib_recur(N - 1) + fib_recur(N - 2);
}

unsigned long long	fib_formula(int N){
	long double fib;
	fib = (long int)(powl((1 + sqrtl(5)) / 2, (long double)N) / sqrtl(5));
	return fib; 
}

unsigned long long	fib_mass(int N){
	long int mass[1000];
	mass[0] = 0;
	mass[1] = 1;
	for(int i = 2; i <= N; i++){
		mass[i] = mass[i - 1] + mass[i - 2];
	}
	return mass[N];
}

unsigned long long	fib_matrix(int N){
	long int mass[2][2] = {{1, 1}, {1, 0}}, mass1[2][2] = {{1, 1}, {1, 0}}, mass2[2][2] = {{1, 1}, {1, 0}}, rez;
	for(int i = 1; i < N; i++){
		mass[0][0] = mass1[0][0] * mass2[0][0] + mass1[0][1] * mass2[1][0];
		mass[0][1] = mass1[0][0] * mass2[0][1] + mass1[0][1] * mass2[1][1];
		mass[1][0] = mass1[1][0] * mass2[0][0] + mass1[1][1] * mass2[1][0];
		mass[1][1] = mass1[1][0] * mass2[0][1] + mass1[1][1] * mass2[1][1];
		for(int j = 0; j <= 1; j++){
			mass1[0][j] = mass[0][j];
			mass1[1][j] = mass[1][j];
		}
	}
	rez = mass[0][1];
	return rez;
}

int main(){
	int N;
	clock_t end, start;
	double seconds;
	printf("Число Фибоначчи N = ");
	scanf("%d", &N);

	start = clock();
	printf("Рекурсия : %llu : ", fib_recur(N));
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f seconds \n", seconds);

	start = clock();
	printf("Формула  : %llu : ", fib_formula(N));
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f seconds \n", seconds);

	start = clock();
	printf("Массив   : %llu : ", fib_mass(N));
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f seconds \n", seconds);

	start = clock();
	printf("Матрицы  : %llu : ", fib_matrix(N));
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f seconds \n", seconds);

	getchar();
	return 0;
}
