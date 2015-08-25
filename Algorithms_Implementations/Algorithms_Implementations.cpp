#include <iostream>
#include <math.h>
#include <array>
#include <vector>
class Algorithms{
private:
	int *x, *y; int begin, end, midpoint;
public:
	int* merge_sort(int* x,  int begin, int end);
	int* merge(int* x,  int begin, int middle, int end);
	int* heap_sort(int* x, int length);
	int* build_max_heap(int* x, int length);
	int* max_heapify(int* x, int node, int length);

};

int* Algorithms::merge_sort(int* x,int begin, int end){
	int middle;
	if(begin < end){
		middle = (begin+end)/2;
		Algorithms::merge_sort(x, begin, middle);
		Algorithms::merge_sort(x, middle+1, end);
		Algorithms::merge(x, begin, middle, end);
	}

	return x;
}
int* Algorithms::merge(int* x,int begin, int middle, int end){
	int *y; int i = begin, k = begin, j = middle+1;
	y = new int[50];
	
	while(i <= middle && j <= end){
		if(x[i] < x[j]){
			y[k] = x[i];
			k++;	i++;
		}
		else{
			y[k] = x[j];
			k++;	j++;
		}
	}
	while(i <= middle){
		y[k] = x[i];
		k++;	i++;
	}
	while(j <= end){
		y[k] = x[j];
		k++;	j++;
	}
	for(i = begin;i < k; i++){ 	x[i] = y[i]; }

	return x;
}

int* Algorithms::heap_sort(int* x, int length){
	
	Algorithms::build_max_heap(x, length);
	for(int i = length; i>0; i--){
		int temp;
		temp = x[i];
		x[i] = x[0];
		x[0] = temp;		
		length--;
		Algorithms::max_heapify(x, 0, length);
	}
	return x;
}

int* Algorithms::build_max_heap(int* x, int length){
	int heap_size = length;
	for(int i = length/2; i >= 0; i--){
		Algorithms::max_heapify(x, i, length);
	}
	return x;
}

int* Algorithms::max_heapify(int* x, int node, int length){
	int left, right;
	if(node!=0){
		 left = 2*node;  right = 2*node+1;
	}
	else{
		 left = 1;  right = 2;
	}
	int largest;
	if(left <= length && x[left] > x[node]){ largest = left; }
	else{ largest = node; }
	if(right <= length && x[right] > x[largest]){ largest = right; }
	if(largest != node){
		int temp;
		temp = x[node];
		x[node] = x[largest];
		x[largest] = temp;
		Algorithms::max_heapify(x, largest, length);
	}
	return x;
}

int main(int argc,char** argv){
	int num;
	std::cout<< "Enter the number of elements: "<< std::endl;
	std::cin>> num;
	int *ar; ar = new int(num);
	
	std::cout<< "Size of the Input Vector: "<< num<< std::endl;	
	
	for(int iter = 0;iter<num;iter++){
	std::cout<< "Enter the number: "<< std::endl;
	std::cin>> ar[iter];
	}
	
	Algorithms n;
	//n.merge_sort(ar,0,num-1); //Invokes Merge Sort
	n.heap_sort(ar,num-1); //Invokes Heap Sort
	for(int iter = 0;iter<num; iter++){
		std::cout<< ar[iter]<< std::endl;	
	}
	return 0;
}