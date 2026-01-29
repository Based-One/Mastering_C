#include "binary.h"
#include "string.h"


int convert(const char *input){
	int strlength = strlen(input) -1;
	int number = 0;
	for (int i =0; i < strlength; i++){
		number += input[i]*2^(strlength-1);

}
return number;


}
