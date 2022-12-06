//#include <stdlib.h>
//#include <stdio.h>
//#include <omp.h>
//#include <iostream>  
//#define NTHREADS 1
//
//using namespace std;
//
//void swap(int array[], int i, int j);
//void bitonicSort(int array[], int l_index, int count, int direction);
//void bitonicMerge(int array[], int l_index, int count, int direction);
//void print(int a[], int n);
//
//
//void swap(int array[], int i, int j) {
//	/**
//	 * Hace swap entre 2 elementos de un arreglo
//	 * array[]: arreglo en el que se va a realizar el swap
//	 * i: elemento 1
//	 * j: elemento 2
//	 */
//
//	int temp;
//	temp = array[i];
//	array[i] = array[j];
//	array[j] = temp;
//}
//
//
//void bitonicSort(int array[], int l_index, int count, int direction) {
//	/**
//	 * Recursivamente hace el sort en el lado izquierdo y derecho del arreglo y despues llama al Merge
//	 * array[]: arreglo que se esta sorteando
//	 * l_index: indice mas bajo del array que se esta utilizando
//	 * count: numero de elementos del array
//	 * direction: determina si se hace sort de manera creciente (1) o decreciente (0)
//	 */
//
//	int k;
//	if (count > 1) {									// si el array tiene >1 elementos
//		k = (count / 2);								// es el indice del medio
//		bitonicSort(array, l_index, k, 1);				// se encarga de ordenar la parte izquierda en orden creciente
//		bitonicSort(array, (l_index + k), k, 0);		// se encarga de ordenar la parte derecha en orden decreciente
//		bitonicMerge(array, l_index, count, direction);	// hace merge en las dos BS creadas 
//	}
//}
//
//
//void bitonicMerge(int array[], int l_index, int count, int direction) {
//	/**
//	 * Recursivamente hace el merge entre 2 subarreglos
//	 * array[]: arreglo que se esta sorteando
//	 * l_index: indice mas bajo del array que se esta utilizando
//	 * count: numero de elementos del array
//	 * direction: determina si se hace sort de manera creciente (1) o decreciente (0)
//	 */
//
//	int k, i;
//	if (count > 1) {										// si el array tiene >1 elementos
//		k = (count / 2);									// es el indice del medio
//		for (i = l_index; i < l_index + k; i++) {			// recorre una parte del array
//			if (direction == (array[i] > array[i + k])) {	// compara un elemento del lado izquierdo con otro del lado derecho
//				swap(array, i, i + k);						// hace swap en caso de que sea necesario
//			}
//		}
//		bitonicMerge(array, l_index, k, direction);			// se encarga de hacer merge en la parte izquierda
//		bitonicMerge(array, (l_index + k), k, direction);	// se encarga de hacer merge en la parte derecha
//	}
//}
//
//
//void print(int array[], int n) {
//	/**
//	 * funcion para imprimir un arreglo
//	 * array[]: arreglo que se quiere imprimir
//	 * n: tamanio del arreglo
//	 */
//	int i;
//	for (i = 0; i < n; i++) {
//		cout << array[i] << " ";
//	}
//}
//
//
//int main() {
//	// genera el array - no es lo mas limpio del mundo pero no me importa
//	const long int array_size = 1 << 10;
//	const long int n_range = 1 << 10;
//	int* r_array = new int[array_size];
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < array_size; i++) {
//		r_array[i] = rand() % n_range;
//	}
//
//	double start, end;				// variables para el tiempo
//	int count = array_size;			// tamanio
//	int direction = 1;				// creciente
//
//	printf("|--- STARTING SORTING ---|\n");
//	printf("Tamanio del Array: %d\n", count);
//	printf("Cantidad de Threads: %d\n", NTHREADS);
//	/*printf("Array before: \n");
//	print(r_array, count);*/
//
//	start = omp_get_wtime();
//	bitonicSort(r_array, 0, count, direction);
//	end = omp_get_wtime();
//
//	/*printf("\nArray after: \n");
//	print(r_array, count);*/
//	printf("\nSorting time: %f\n", end - start);
//
//}
//
//
