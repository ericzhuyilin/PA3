/*
 * Filename: testparseNum
 * Author: Yilin Zhu
 * Userid: A15862322
 * Description: Unit test program to test the function parseNum().
 * Date: 2022 9.1
 * Sources of Help: Lecture slides, C documentation.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pa3.h"
#include "pa3Strings.h"
#include "test.h"

void testparseNum(){
    // test parseNum when the value is 190 in decimal
    char* arr1[] = {
        "first",
	"second",
	"0x433E0000"    // decimal: 190
    };
    char str1[] = "0x433E0000";
    unsigned long val1 = parseNum(arr1);
    unsigned long expected1 = strtoul(str1, NULL, 0);
    TEST( val1 == expected1 );

    // test parseNum when the value is 888 in decimal
    char* arr2[] = {
        "first",
	"second",
	"445E0000"
    };
    char str2[] = "445E0000";
    unsigned long val2 = parseNum(arr2);
    unsigned long expected2 = strtoul(str2, NULL, 0);
    TEST( val2 == expected2 );

    // test parseNum when the value is 1234 in decimal
    char* arr3[] = {
        "first",
	"second",
	"449A4000"
    };
    char str3[] = "449A4000";
    unsigned long val3 = parseNum(arr3);
    unsigned long expected3 = strtoul(str3, NULL, 0);
    TEST( val3 == expected3 );

    // test parseNum with edge case 0
    char* arr4[] = {
        "first",
	"second",
	"00000000"
    };
    char str4[] = "00000000";
    unsigned long val4 = parseNum(arr4);
    unsigned long expected4 = strtoul(str4, NULL, 0);
    TEST( val4 == expected4 );

    // test parseNum with edge case -1234
    char* arr5[] = {
        "first",
	"second",
	"0xC49A4000"
    };
    char str5[] = "0xC49A4000";
    unsigned long val5 = parseNum(arr5);
    unsigned long expected5 = strtoul(str5, NULL, 0);
    TEST( val5 == expected5 );
}

int main(){
    fprintf( stderr, "Testing parseNum...\n\n" );
    testparseNum();
    fprintf( stderr, "\nDone running tests.\n" );
    return 0;
}
