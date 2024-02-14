//
//  main.cpp
//  ch4_breakout
//
//  Created by Steve Yang on 9/14/21.
//  Modified by Sid Bhatia on 2/6/24.
//
#include <iostream>
#include <time.h>
#include "DoubleItem.h"

#include <iostream>
#include <time.h>
#include "DoubleItem.h"

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <number of objects> <iteration 1> <iteration 2> ... <iteration N>\n";
        return 1;
    }

    size_t arraySize = static_cast<size_t>(std::atoi(argv[1])); // Convert first argument to size_t for array size

    // Loop over each additional argument to get the number of iterations for each test
    for (int argIndex = 2; argIndex < argc; ++argIndex) {
        int test = std::atoi(argv[argIndex]); // Convert argument to int for number of iterations
        clock_t startTime, endTime;
        double totalTime = 0.0;

        // Run the allocation test 'test' times
        for (int i = 0; i < test; ++i) {
            startTime = clock();
            
            // Allocate an array of DoubleItem pointers
            DoubleItem** data = new DoubleItem*[arraySize];
            for (size_t j = 0; j < arraySize; ++j) {
                data[j] = new DoubleItem(static_cast<double>(j));
            }
            
            // Record the end time before deallocation begins
            endTime = clock();
            totalTime += static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

            // Deallocate the objects
            for (size_t j = 0; j < arraySize; ++j) {
                delete data[j];
            }
            delete[] data;
        }

        // Calculate and print the average time
        double averageTime = totalTime / test;
        std::cout << "Test with " << arraySize << " objects, run " << test
                  << " times: Average time = " << averageTime << " seconds." << std::endl;
    }
    
    return 0;
}

