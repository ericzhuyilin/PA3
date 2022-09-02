/*
 * Filename: testextractParts
 * Author: Yilin Zhu
 * Userid: A15862322
 * Description: Unit test program to test extractParts().
 * Date: 2022 9.1
 * Sources of Help: Lecture slides, C documentation.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pa3.h"
#include "pa3Strings.h"
#include "test.h"

void testextractParts(){
    // test extractParts on decimal value of 190
    ieeeParts_t s1;
    // create a IEEE-754 floating point number as unsigned long
    char str1[] = "0x433E0000";
    unsigned long num1 = strtoul(str1, NULL, 0);

    // mantissa, exp, and sign are calculated in advance
    extractParts(num1, &s1);
    TEST( s1.sign == 0 );
    TEST( s1.exp == 7 );
    TEST( s1.mantissa == 4063232 );



    // test extractParts on decimal value of 88888888 
    ieeeParts_t s2;
    char str2[] = "0x4CA98AC7";
    unsigned long num2 = strtoul(str2, NULL, 0);
    extractParts(num2, &s2);
    TEST( s2.sign == 0 );
    TEST( s2.exp == 26 );
    TEST( s2.mantissa == 2722503 );



    // test extractParts on negative value
    // decimal value of -1234
    ieeeParts_t s3;
    char str3[] = "0xC49A4000";
    unsigned long num3 = strtoul(str3, NULL, 0);

    extractParts(num3, &s3);
    TEST( s3.sign == 1 );
    TEST( s3.exp == 10 );
    TEST( s3.mantissa == 1720320 );



    // test edge case for rational numbers
    // decimal calue of 88.25
    ieeeParts_t s4;
    char str4[] = "0x42B08000";
    unsigned long num4 = strtoul(str4, NULL, 0);

    extractParts(num4, &s4);
    TEST( s4.sign == 0 );
    TEST( s4.exp == 6 );
    TEST( s4.mantissa == 3178496 );
    
}

int main(){
    fprintf( stderr, "Testing parseNum...\n\n" );
    testextractParts();
    fprintf( stderr, "\nDone running tests.\n" );
    return 0;
}
