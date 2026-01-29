#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number){
	unsigned int sum_of_squares = 0;
	for (unsigned int i = 0 ; i <= number ; i++){
		sum_of_squares += i * i; 
	
	}
	return sum_of_squares;

}



unsigned int square_of_sum(unsigned int number){
	unsigned int square = 0;
	for (unsigned int i = 0; i <= number; i++){
		square += i; 
	}
	return square * square;
}


unsigned int difference_of_squares(unsigned int number){
	return square_of_sum(number) - sum_of_squares(number);

}

