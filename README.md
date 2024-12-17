Testing using a RandomNumber Array of size 1000000
Sorting Algorithm Comparison

--------------------------------------------------------
Algorithm        | Time Complexity   | Time Taken (s)
--------------------------------------------------------
Binary Sort      | O(n log n)        | 3.37506
Bubble Sort      | O(n^2)            | 20.0136
Selection Sort   | O(n^2)            | 7.1496
--------------------------------------------------------

Even though Bubble Sort and Selection Sort have the same time complexity of O(n²), the reason Bubble Sort takes more time in practice compared to Selection Sort, as shown in your table, lies in the constant factors and the nature of the algorithms. Let's break it down:

Key Differences Between Bubble Sort and Selection Sort:
Number of Swaps:

Bubble Sort tends to perform more swaps than Selection Sort.
In Bubble Sort, elements are swapped every time two elements are out of order. Since it compares adjacent elements and swaps them, it may end up making multiple swaps during a single pass through the array.
In Selection Sort, a swap happens only once per iteration (when the minimum element is found and swapped with the current element). Even though there are more comparisons in Selection Sort, the actual number of swaps is generally much lower.
More swaps result in more operations, which increases the runtime, especially when the array is large.

Number of Comparisons:

Both algorithms have O(n²) comparisons, but the constant factors differ:
Bubble Sort does more redundant comparisons. For example, in each pass, even after the largest element has been "bubbled" to its correct position, it still continues to compare the remaining elements. This means the algorithm keeps making comparisons even after it's obvious that the array is partially sorted.
Selection Sort, on the other hand, does not waste time after finding the minimum element for each iteration. Once the minimum is found, it is swapped into place, and no further unnecessary comparisons are made within the current pass.
Early Stopping (Optimization):

Bubble Sort can be optimized with a flag to stop early if no swaps are made during a pass (which would indicate the array is already sorted). However, this optimization doesn't eliminate the fundamental number of comparisons in the worst case; it just reduces the time taken in some cases (e.g., if the array is already partially sorted).
Selection Sort is less likely to benefit from early stopping because it always performs a full pass to find the minimum value in the unsorted portion of the array, even if the array is almost sorted.
Why Does Bubble Sort Take More Time?
Bubble Sort requires more swaps because adjacent elements are swapped each time they are out of order. This increases the number of operations compared to Selection Sort, which only swaps once per pass.
Additionally, Bubble Sort might take slightly more time due to the overhead of swapping multiple times, whereas Selection Sort minimizes the number of swaps by doing only one swap per iteration.
Practical Example:
For an array of size n, consider the following:

Bubble Sort compares and potentially swaps every adjacent pair of elements multiple times in each pass. This makes the process slower because of the high number of operations involved in the swapping.
Selection Sort makes n-1 passes, and each pass involves finding the minimum element and swapping it once. This minimizes the number of swaps, although the number of comparisons remains the same.
Summing It Up:
Bubble Sort takes more time because:
It does more swaps, and swapping is an expensive operation in terms of time.
Even though both algorithms have the same time complexity (O(n²)), the constant factors involved in the swaps make Bubble Sort slower in practice.
Selection Sort, on the other hand, only performs one swap per iteration (for each element in the array), resulting in fewer actual operations compared to Bubble Sort, even though both algorithms have the same overall complexity.
This is a good example of how time complexity (like O(n²)) doesn't always tell the full story of how an algorithm behaves in practice. Constant factors and the nature of the operations involved (like swaps vs. comparisons) can have a significant impact on the actual runtime.
