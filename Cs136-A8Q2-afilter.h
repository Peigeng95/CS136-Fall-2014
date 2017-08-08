#include <stdbool.h>

// see section 9 
struct dyn_array {
   int *data;
   int len;
   int max;
};

// afilter(da, f) modifies the dynamic array da by removing
//     all elements where f(element) is false
//     elements where f(element) is true may be shifted to lower indices accordingly.
//     (i.e., the original order of elements is preserved)
//   PRE:  da != NULL, is a valid dyn_array (e.g., len <= max)
//   POST: 0 <= da->len <= original da->len
//         da->max is unchanged
//         f(da->data[i]) is true for 0 <= i <= da->len -1
//         elements between da->len .. da->max -1 are arbitrary (garbage)
//   TIME: O(n), where n is the original da->len [assuming f is O(1)].
void afilter(struct dyn_array *da, bool (*f)(int));
