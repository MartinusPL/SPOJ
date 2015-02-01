#include <stdio.h>
#include <math.h>
#include <cmath>

using namespace std;

#define STR_SIZE 5000

// translates character from source number into its decimal value
long double translateToNumber(char c){
	int ascii = (int)c;

	long double ret = 0;

	if ((ascii >= 48) && (ascii <= 57)){
		ret = (float)(ascii - 48); // '0'->0, '1'->1 etc.
	}else {
		ret = (float)(ascii - 55); // 'A'->10, 'B'->11 etc.
	}

	return ret;
}

// translates character from source number into its decimal value
char translateToChar(int n){
	char ret = 0;

	if ((n >= 0) && (n <= 9)){
		ret = (n + 48); // 0->'0', 1->'1' etc.
	}else {
		ret = (n + 55); // 10->'A', '11'->B etc.
	}

	return ret;
}

//long double pow(long double a, long double b){
//	long double r = 1;
//	for (long double i=0; i<b; i++){
//		r *= a;
//	}
//
//	return r;
//}

long double trunc(long double x) {
    union {
        long double    f;
        unsigned long long int i;
    } val;
    val.f = x;
    int exponent = (val.i >> 23) & 0xff; // extract the exponent field;
    int fractional_bits = 127 + 23 - exponent;
    if (fractional_bits > 23) // abs(x) < 1.0
        return 0.0;
    if (fractional_bits > 0)
        val.i &= ~((1U << fractional_bits) - 1);
    return val.f;
}

int main(){

	int count;
	scanf("%d",&count);
	for (int i=0; i<count; i++){
		// read data
		char* n = new char[STR_SIZE];
		int r;
		int s;
		scanf("%s %d %d",n,&r,&s);
		
		// get size of n
		long double n_decimal = 0;
		unsigned long long int n_size = 0;
		for (unsigned long long int j=0; j<STR_SIZE; j++){
			if (n[j] == 0){
				n_size = j;
				break;
			}
		}



		// transform n (r-based) to decimal
		for (unsigned long long int j=0; j<n_size; j++){
			long double power =  n_size - j - 1;
			long double translated = translateToNumber(n[j]);
			n_decimal += translated * pow((long double)r,power);
		}

		// free memory - n not needed anymore
		delete[] n;

		// transform n to s-based number
		char *result = new char[STR_SIZE];
		unsigned long long int result_count = 0;
		long double number = (long double)n_decimal; // zmienilem unsigned long long int na double ale i tak traci precyzje na ostatnich dwoch testach // TODO: fix it
		while(number != 0){
			int rest = fmod(number,s);
			result[result_count] = translateToChar(rest);
			number = floor(number / s);
			result_count ++;
		}

		// return '0' for n=0 - individual case
		if (result_count == 0){
			result[result_count] = '0';
			result_count ++;
		}

		// invert s-based number
		char* result_inv = new char[result_count+1];
		for (unsigned long long int j=0; j<result_count; j++){
			unsigned long long int index = result_count - j - 1;
			result_inv[j] = result[index];
		}

		// add end-of-string character
		result_inv[result_count] = 0;

		// print result
		printf("%s\n",result_inv);

		// free memory
		delete[] result;
		delete[] result_inv;
	}

	return 0;
}