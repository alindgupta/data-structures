#include "search.hpp"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <cassert>

// O(n^2) worst case
// O(n) best case
void inplace_bubblesort(int *arr, unsigned int length) //-> IO ()
{
    int temp;
   
    for (int i = length; i > 1; i--) {
         int not_sorted = 0;
        
        for (int j = 0; j < i - 1; j++) {
            
            if (arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                not_sorted++;
            }
        }
        
        // visualization of intermediate steps
        for (int q = 0; q < length; q++) {
            printf("%i\t", arr[q]);
        }
        printf("\n");
        
        // break if did not enter the `if` block on this iteration through the array
        // should improve average-case performance
        if (!not_sorted) {
            break;
        }
    }
}

// helper function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// try 1, best case is not O(n) comparisons
void insertion_sort(std::vector<int>& arr)
{
    
    int length = static_cast<int>(arr.size());
    
    for (int i = 1; i < length; i++) {
        
        // for diagnostics
        int comparisons = 0;
        int swaps = 0;
        
        for (int j = i; j > 0; j--) {
            comparisons++;
            
            if (arr[j] < arr[j-1]) {        // this loop will be O(n^2) always
                swap(&arr[j], &arr[j-1]);
                swaps++;
            }
        }
        std::cout << "Comparisons: " << comparisons << "\t" << "Swaps: " << swaps << '\n';
    }
    
    for (auto i: arr) {
        std::cout << i << '\t';
    }
    std::cout << std::endl;
    
}



// correct version
void insertion_sort2(std::vector<int>& arr)
{
    
    
    int length = static_cast<int>(arr.size());
    
    int curr;
    int j;
    
    for (int i = 1; i < length; i++) {
        
        // for diagnostics
        int swaps = 0;
        int comparisons = 0;
        
        curr = arr[i];
        j = i;
        comparisons++;
        
        while (j > 0 && curr < arr[j-1]) {
            arr[j+1] = arr[j];
            j--;
            swaps++;
        }
        arr[j] = curr;
        
        
        std::cout << "Comparisons: " << comparisons << "\t" << "Swaps: " << swaps << '\n';
    }
    
    for (auto i: arr) {
        std::cout << i << '\t';
    }
    std::cout << std::endl;
    
}


// selection sort
void selection_sort(std::vector<int>& arr) {
    
    int length = static_cast<int>(arr.size());
    
    for (int i = 0; i < length; i++) {
        
        int curr_min = arr[i];
        int idx_curr_min = i;
        
        for (int j = i; j < length; j++) {
            if (arr[j] < curr_min) {
                curr_min = arr[j];
                idx_curr_min = j;
            }
        }
        
        if (idx_curr_min != i) {
            swap(&arr[i], &arr[idx_curr_min]);
        }
        
        // intermediates
        for (int q = 0; q < length; q++) {
            printf("%i\t", arr[q]);
        }
        printf("\n");
    }
}


































