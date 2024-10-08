/** Daily Coding Problem 1084
 * This problem was asked by Stripe. 
 * reduce(), also known as fold(), is a function that takes in an array, 
 * a combining function, and an initial value, and builds up a result
 * by calling the combining function on each element of the array, 
 * from left to right. 
 * Implement your own version of reduce(). 
 * ------------------------------
 * Author: Ewan Burnett (EwanBurnettSK@Outlook.com)
 * Date: 2024/10/08
*/

#include <stdint.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <functional> 

#if ENABLE_UNIT_TESTS
#include <gtest/gtest.h>
#endif

float Sum(float a, float b){
    return a + b; 
}

template<typename T>
T Reduce(T* arrayData, const size_t count, T(*function)(T, T), T initialValue){

    T acc = initialValue; 

    for(size_t i = 0; i < count; i++){
        acc = function(acc, arrayData[i]);
    }

    return acc;
}

#if ENABLE_UNIT_TESTS
TEST(Daily_Coding_Problem_1084, Case_1) {
    float vals[] = {
        1.0f, 2.0f, 3.0f, 4.0f
    };
    
    float result = Reduce(vals, sizeof(vals) / sizeof(float), Sum, 0.0f);
    EXPECT_FLOAT_EQ(result, 10.0f);
 
}
#endif

int main(int argc, char* argv[]) {
    printf("Daily Coding Problem 1084\n\n");
    
    float vals[] = {
        1.0f, 2.0f, 3.0f, 4.0f
    };
    
    float result = Reduce(vals, 4, Sum, 10.0f);
    printf("Result = %f!\n", result);


#if ENABLE_UNIT_TESTS
    //Optionally run Unit Tests. 
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
#else
    return 0; 
#endif
}
