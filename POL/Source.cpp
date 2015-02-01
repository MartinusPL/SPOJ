#include <stdio.h>

#define STR_MAX 2010

int main(){

	int count;
	scanf("%d",&count);
	for (int i=0; i<count; i++){
		char* str = new char[STR_MAX];

		scanf("%s",str);
		int length = 0;
		for (int j=0; j<STR_MAX; j++){
			if (str[j] == 0){
				length = j;
				break;
			}
		}

										
		for (int j=0; j<length/2; j++){     // print only half of the characters
			printf("%c",str[j]);			// print character
		}

		printf("%c",10);					// print new line

		delete[] str;
	}

	return 0;
}