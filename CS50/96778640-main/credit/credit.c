#include <stdio.h>
#include <cs50.h>
int checkType(long long number){
	//1 2 3 is AMEX, MasterCard, VISA
	if(number/10000000000000==34 || number/10000000000000==37) return 1;
	else if(number>=5100000000000000 && number<5600000000000000) return 2;
	else if(number/1000000000000000==4 || number/1000000000000==4) return 3; else return 0;
}
int checkNumber(long long number){
	int sum=0;
	while(number>0){
		sum += number%10;
		number/=10;
	}
	return sum;
}
int main(void){
	long long number;
	do {
		number = get_long_long("Number: ");
	} while (number<=0);
    long long n = number;
	int cout = 1;
	int sum = 0;
	while (number > 0){
		if(cout%2==1){
			sum += number % 10;
			number /= 10;
			cout++;
		} else {
			if(number%10 >= 5) {
				sum += checkNumber(number%10*2);
				number /= 10;
			} else {
				sum += number%10*2;
				number/=10;
			}
			cout++;
		}
	}
	if (sum%10==0)
		switch(checkType(n)){
			case 1:
				printf("AMEX\n");
				break;
			case 2:
				printf("MASTERCARD\n");
				break;
			case 3:
				printf("VISA\n");
				break;
            case 0:
                printf("INVALID\n");
                break;
		}
		else printf("INVALID\n");
}