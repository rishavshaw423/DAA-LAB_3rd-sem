#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tossCoin(double biasProbability) {
    double r = (double)rand() / RAND_MAX;
    return (r < biasProbability) ? 1 : 0;
}

int main(void) {
    int totalTosses;
    double biasProbability;

    srand((unsigned int)time(NULL));

    printf("Enter the total number of tosses to simulate: ");
    scanf("%d", &totalTosses);

    printf("Enter the bias probability for the biased coin (e.g. 0.7 for 70%% heads): ");
    scanf("%lf", &biasProbability);

    if (biasProbability < 0.0 || biasProbability > 1.0) {
        printf("Error: bias probability must be between 0 and 1.\n");
        return 1;
    }

    long fairHeadsCount = 0;
    long biasedHeadsCount = 0;

    double *fairProb = malloc(totalTosses * sizeof(double));
    double *biasedProb = malloc(totalTosses * sizeof(double));

    for (int i = 1; i <= totalTosses; i++) {
        int fairResult = tossCoin(0.5);
        int biasedResult = tossCoin(biasProbability);

        if (fairResult == 1) fairHeadsCount++;
        if (biasedResult == 1) biasedHeadsCount++;

        fairProb[i - 1] = (double)fairHeadsCount / i;
        biasedProb[i - 1] = (double)biasedHeadsCount / i;
    }

    printf("\nFinal probability of heads (Fair coin): %lf\n", (double)fairHeadsCount / totalTosses);
    printf("Final probability of heads (Biased coin, target %.2f): %lf\n",
           biasProbability, (double)biasedHeadsCount / totalTosses);

    FILE *gp = popen("gnuplot -persistent", "w");
    if (gp == NULL) {
        printf("GNUplot not found!\n");
        return 1;
    }

    fprintf(gp, "set title 'Fair vs Biased Coin: Convergence of Probability of Heads'\n");
    fprintf(gp, "set xlabel 'Number of Tosses'\n");
    fprintf(gp, "set ylabel 'Running Probability of Heads'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set key top right\n");
    fprintf(gp, "set yrange [0:1]\n");
    fprintf(gp, "set logscale x\n");

    fprintf(gp,
        "plot "
        "'-' with lines lw 2 lc rgb 'blue' title 'Fair Coin (p=0.5)', "
        "'-' with lines lw 2 lc rgb 'red' title 'Biased Coin (p=%.2f)', "
        "0.5 with lines lw 1 dt 2 lc rgb 'black' title 'Expected 0.5', "
        "%lf with lines lw 1 dt 2 lc rgb 'gray' title 'Expected Bias'\n",
        biasProbability, biasProbability);

    for (int i = 0; i < totalTosses; i++) {
        fprintf(gp, "%d %lf\n", i + 1, fairProb[i]);
    }
    fprintf(gp, "e\n");

    for (int i = 0; i < totalTosses; i++) {
        fprintf(gp, "%d %lf\n", i + 1, biasedProb[i]);
    }
    fprintf(gp, "e\n");

    pclose(gp);

    free(fairProb);
    free(biasedProb);

    printf("\nGraph plotted successfully.\n");

    return 0;
}