
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

void quick_sort(int array[], int left, int right);

int main()
{
	int i, num[10];
	srand(time(NULL));	// random seed 생성
	
	printf("Quick sort\n\n");
	printf("The original array is : \n");

	// random array 생성
	for(i=0; i<10; i++)
	{
		num[i] = (long) rand() *100 / RAND_MAX;	
		printf("%d ", num[i]);
	}
	
	printf("\n");
	
	// 정렬 시작 
	quick_sort(num, 0, 9);

	printf("\n\n The array is sorted!\n");
	
	// 최종값 출력
	for(i=0; i<10; i++)
	{
		printf("%d  ", num[i]);
	}

	printf("\n");

	return 0;
}

void quick_sort(int array[], int left, int right)
{
	int i, j;
	int k;
	int temp;
	int pivot;

	if(DEBUG) printf("quick_sort [%d]~[%d] start\n", left, right); 

	if(left < right) {
		pivot = array[left];
		i = left;
		j = right+1;

		do{
			do{
				i++;
			}while(array[i] < pivot);
		
			do{	
				j--;
			}while(array[j] > pivot);
	
			if(DEBUG) printf("i-> %d / j-> %d\n", i, j);	
			// i : pivot 보다 크다, j : pivot 보다 작다.
			// 그런데 i 가 j 보다 앞에 있으면 
			if( i < j ) {	
				if(DEBUG) puts("do change i, j");
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
	
				if(DEBUG){
					// 최종값 출력
					for(k=0; k<10; k++)
					{
						printf("%d  ", array[k]);
					}
					printf("\n");
				}
			}
			else {
				if(DEBUG) puts("break");
				break;
			}

		}while(i < j); // 만나지 않으면 sort 더 수행

		if(DEBUG) puts("if change left, j");
		// pivot 값과 j 를 교환한다. 왜냐하면 j 는 pivot 보다 작으니까.
		temp = array[j];
		array[j] = array[left];
		array[left] = temp;

		if(DEBUG){
			// 최종값 출력
			for(k=0; k<10; k++)
			{
				printf("%d  ", array[k]);
			}
			printf("\n");
		}

		quick_sort(array, left, j-1);
		quick_sort(array, j+1, right);
	}
	if(DEBUG) printf("quick_sort [%d]~[%d] end\n\n", left, right);
}



