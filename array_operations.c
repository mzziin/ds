#include <stdio.h>
#include <stdlib.h>
#define N 7
int arr[N] = {12, 34, 55, 6, 2, 45, 99};

void search();
void sort();
void min_max();
void avg();
void reverse();

int main(){
	int choice;
	printf("Enter a choice: \n1)search\n2)sort\n3)min and max\n4)avg\n5)reverse\n");
	scanf("%d", &choice);
	
	switch (choice){
		case 1:
			search();
			break;
		case 2:
			sort();
			break;
		case 3:
			min_max();
			break;
		case 4:
			avg();
			break;
		case 5:
			reverse();
			break;
		default:
			exit(1);
	}
}

void search(){
	int num;
	printf("Enter number to search: ");
	scanf("%d", &num);
	for (int i=0; i<N; i++){
		if(arr[i] == num){
			printf("found %d at position: %d\n", num, i+1);
			return;
		}
	}
	
	printf("not found\n");
}

void sort(){
	for(int i=0;i<N;i++){
		for(int j=i+1; j<N;j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void min_max(){
	int min, max;
	min = arr[0];
	max = arr[0]; 
	for (int i=0; i<N; i++){
		if(arr[i] > max)
			max = arr[i];
		if(arr[i] < min)
			min = arr[i];
	}
	printf("min: %d, max: %d", min, max);
}
void avg(){
int sum=0;
	for (int i=0; i<N; i++){
		sum += arr[i];
	}
	printf("average: %d", sum/N);
}
void reverse(){
	for(int i=0;i<N;i++){
		for(int j=i+1; j<N;j++){
			if(arr[i] < arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}




















