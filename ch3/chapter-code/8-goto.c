/***
 * goto example:
 *
 * Imagine we are attempting to see if arrays
 * a and b have at least one element in common:
 *
 * for (i = 0; i < n; ++i) {
 *     for (j = 0; j < m; ++j) {
 *         if (a[i] == b[j]) {
 *             goto found;
 *         }
 *     }
 * }
 *
 * found: 
 *    [code to handle case in nested loops here]
 *
 * Personal note: makes me think of exceptions, to some extent
 */
