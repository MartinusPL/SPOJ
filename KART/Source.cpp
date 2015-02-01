#include <stdio.h>

int main(){

	int count;
	scanf("%llu",&count);
	for(int i=0; i<count; i++){
		int number;
		scanf("%llu",&number);
		int count = 0;
		for(int i=5; number >= i ; i = i*5){
			count += number / i;
		}
		printf("%d\n",count);
	}

	return 0;
}