#include "binary.h"
#include "string.h"


int convert(const char *input){
	int len = strlen(input);
	int number = 0;
	for (int i = len -1; i > 0; i--){
	number =  (number << 1) + (input[i] - '0');
	}
return number;


}
