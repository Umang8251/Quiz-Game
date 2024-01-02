//WHY MAX HEAP ?
/*1)Constant Time Retrieval: In a max-heap, the maximum element is always at the root. Thus, finding the maximum
element involves a simple lookup operation at the root, resulting in constant time complexity (O(1)). In 
contrast, searching for the maximum element in an unsorted array would require linear time (O(n)).
2)Space Efficiency: Max-heaps can be implemented using an array, providing a space-efficient representation. 
Each element in the array corresponds to a node in the heap, and the structure of the heap allows for efficient
storage.*/

#include <stdio.h>
#include <stdlib.h>
#include "Max_score.h"
void max_score(int* scores) {
    

    // Calculate the number of elements in the array
    int numElements = 3;

    // Initialize the maximum score with the first element of the array
    int maxScore = scores[0];

    // Iterate through the array to find the maximum score
    for (int i = 1; i < numElements; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
        }
    }

    // Print the maximum score
    printf("The highest score is: %d\n", maxScore);
}
