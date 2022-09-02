#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "pa3.h"
#include "pa3Strings.h"

#define FLAGS "-s"
#define FLAGH "-h"

int main(int argc, char* argv[]){
    if(argc != 3){
        fprintf(stderr, INVALID_ARGS);
	fprintf(stderr, SHORT_USAGE);
	return EXIT_FAILURE;
    }

    // char flagS[] = {"-s"};
    // char flagH[] = {"-h"};
    // point to argv[2] in parseNum
    unsigned long num = parseNum(argv);

    if(strcmp(argv[1], FLAGS) == 0){
        ieeeParts_t s;
	extractParts(num, &s);
	printf(SIGN_STR, s.sign);//exp mantissa
	printf(EXP_STR, s.exp);
	printf(MANTISSA_STR, s.mantissa);
    }

    if(strcmp(argv[1], FLAGH) == 0){
        ieeeParts_t *h = malloc(sizeof(ieeeParts_t));
	extractParts(num, h);
	printf(SIGN_STR, h->sign);//exp mantissa
	printf(EXP_STR, h->exp);
	printf(MANTISSA_STR, h->mantissa);
    }

   return EXIT_SUCCESS; 
}
