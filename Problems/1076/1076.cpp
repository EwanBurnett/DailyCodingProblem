/** Daily Coding Problem 1076
 * This problem was asked by Squarespace.
 * Write a function, add_subtract, which alternately adds and subtracts curried arguments.
 * Here are some sample operations:
 * add_subtract(7) -> 7
 * add_subtract(1)(2)(3) -> 1 + 2 - 3 -> 0
 * add_subtract(-5)(10)(3)(9) -> -5 + 10 - 3 + 9 -> 11
 * ------------------------------
 * Author: Ewan Burnett (EwanBurnettSK@Outlook.com)
 * Date: 2024/09/23
*/

#include <stdint.h> 
#include <stdlib.h> 
#include <stdio.h>

#if ENABLE_UNIT_TESTS
#include <gtest/gtest.h>
#endif

//To see the output of different solutions, change this macro. 
#define SOLUTION 1

#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(*arr)

int64_t add_subtract(const int32_t* vals, const uint32_t count)
{
    //Catch invalid array sizes. 
    if (count == 0) {
        return 0; 
    }
    //Catch invalid arrays
    if (vals == nullptr) {
        return 0; 
    }

#if SOLUTION == 0
    //Brute force Solution
    int64_t accumulator = 0; 
    for(uint32_t i = 0; i < count; i++)
    {
        if (i == 0) {
            accumulator = vals[i]; 
            continue;
        }
        //If the index is even, add. Else, subtract. 
        if (i % 2) {
            accumulator += vals[i];
        }
        else {
            accumulator -= vals[i];
        }
    }

    return accumulator; 
#elif SOLUTION == 1
    //A better Solution for large data sets, at the cost of slightly more storage. 
    //Split into 2 linear loops over the value range, and avoid branching. 
    //This could be trivially parallelized, and is easier for the compiler to optimize. 
    int64_t accumulator = vals[0]; 

    int64_t positive = 0;
    int64_t negative = 0; 

    //+
    for(int i = 1; i < count; i+=2)
    {
        positive += vals[i]; 
    }

    //-
    for(int i = 2; i < count; i+=2)
    {
        negative -= vals[i]; 
    }

    accumulator += (positive + negative); 
#else
    return 0;
#endif
}

#if ENABLE_UNIT_TESTS
TEST(Daily_Coding_Problem_1076, Case_1) {
    int32_t vals[] = { 7 };
    uint64_t res = add_subtract(vals, ARRAY_SIZE(vals));
    EXPECT_EQ(res, 7);
}

TEST(Daily_Coding_Problem_1076, Case_2) {
    int32_t vals[] = { 1, 2, 3 };
    uint64_t res = add_subtract(vals, ARRAY_SIZE(vals));
    EXPECT_EQ(res, 0);
}

TEST(Daily_Coding_Problem_1076, Case_3) {
    int32_t vals[] = { -5, 10, 3, 9 };
    uint64_t res = add_subtract(vals, ARRAY_SIZE(vals));
    EXPECT_EQ(res, 11);
}

#endif

int main(int argc, char* argv[]) {
    printf("Daily Coding Problem 1076\n\n");

    uint32_t count = 0; 
    int32_t* vals = nullptr;

    //Parse CMD Arguments
    if (argc > 1) {   //argv[0] is the executable name, so argc must be greater than 1. 
        count = argc - 1; 
        vals = new int32_t[count]; //Allocate enough space for each supplied value. 
        for (uint32_t i = 0; i < count; i++) {
            vals[i] = (int32_t)atoi(argv[i + 1]);    //Store each value in our array. 
        }
    }

    //Handle the edge case of no values being supplied. 
    if (vals) {
        int64_t result = add_subtract(vals, count);

        printf("Running add_subtract: [");
        //Output the result to the console and exit. 
        for (uint32_t i = 0; i < count; i++) {
            printf("%d%s",vals[i], (i != count - 1) ? ((i % 2) ? " - " : " + ") : "");  //Apply some formatting to our output. 
        }
        printf("] -> %d\n", result); 

        delete[] vals; 
    }
    else {
        printf("Please supply a list of values to process.\n");
    }

#if ENABLE_UNIT_TESTS
    //Optionally run Unit Tests. 
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
#else
    return (vals == nullptr);
#endif
}
