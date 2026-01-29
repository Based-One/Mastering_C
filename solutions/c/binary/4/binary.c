#include "binary.h"
#include "string.h"


int convert(const char *input){
	int number = 0;
	for (int i = 0; input[i] != '\0' ; i++){
	number =  (number << 1) + (input[i] - '0');
	}
return number;


}
