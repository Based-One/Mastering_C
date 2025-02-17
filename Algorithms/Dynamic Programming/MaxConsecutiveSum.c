#include <limits.h>
#include <math.h>
#include <stdio.h>
int maxProfit (int *prices, int pricesSize) {
    double profit = 0;
    double mini = INT_MAX;
    double *prices1 = (double*) prices;
    double pricesSize1 = (double) pricesSize;
    for (int i = 0; i < pricesSize1; ++i) {
        mini = fmin(mini,prices1[i]);
        if (mini <prices1[i]) {
            profit = fmax(profit,(prices1[i] - mini));
        }
    }
    return (int) profit;

}
