/** Daily Coding Problem 928
 *  This problem was asked by Microsoft.
 *  A number is considered perfect if its digits sum up to exactly 10.
 *  Given a positive integer n, return the n-th perfect number.
 *  For example, given 1, you should return 19. Given 2, you should return 28.
 *  ------------------------------
 *  Author: Ewan Burnett (EwanBurnettSK@Outlook.com)
 *  Date: 2024/09/23
*/

#include <stdint.h> 
#include <stdlib.h> 
#include <stdio.h>

#if ENABLE_UNIT_TESTS
#include <gtest/gtest.h>
#endif

uint64_t perfect_number(const uint64_t n){
    if(n < 10){
        return ((n * 10) + (10 - n));     
    }

    //Sum up each digit 
    uint64_t sum = 0; 
    uint64_t tmp = n;

    while(tmp > 0){
        sum += tmp % 10; 
        tmp /= 10; 
    }

    printf("sum = %d.\n", sum); 

    return 0; 
}

#if ENABLE_UNIT_TESTS
TEST(Daily_Coding_Problem_928, Case_1) {
    uint64_t num = perfect_number(1);
    EXPECT_EQ(num, 19);
}

TEST(Daily_Coding_Problem_928, Case_2) {
    uint64_t num = perfect_number(2);
    EXPECT_EQ(num, 28);
}
#endif

int main(int argc, char* argv[]){
    printf("Daily Coding Problem 928\n\n"); 

    uint64_t num = 0; 
    
    //Parse CMD Arguments
    if(argc > 1){   //argv[0] is the executable name, so argc must be greater than 1. 
        //This is just an example program, so forgo any safety checks. 
        num = atoi(argv[1]);
    } 
    uint64_t perfectNum = perfect_number(num); 

    //Output the result to the console and exit. 
    printf("The Perfect Number for %d is %d.\n", num, perfectNum);
#if ENABLE_UNIT_TESTS
    //Optionally run Unit Tests. 
    testing::InitGoogleTest(&argc, argv); 

    return RUN_ALL_TESTS(); 
#else
    return 0; 
#endif
}
