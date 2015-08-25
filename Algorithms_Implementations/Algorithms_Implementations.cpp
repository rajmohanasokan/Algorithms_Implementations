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
			k++;
			i++;
		}
		else{
			y[k] = x[j];
			k++;
			j++;
		}
	}
	while(i <= middle){
		y[k] = x[i];
		k++;
		i++;
	}
	while(j <= end){
		y[k] = x[j];
		k++;
		j++;
	}
	for(i = begin;i < k; i++){ 
		x[i] = y[i];
		
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
	

	//std::cout<< "ar.begin: "<< *ar.begin()<< std::endl; 
	
	Algorithms n;
	n.merge_sort(ar,0,num-1);
	for(int iter = 0;iter<num; iter++){
		std::cout<< ar[iter]<< std::endl;	
	}
	return 0;
}