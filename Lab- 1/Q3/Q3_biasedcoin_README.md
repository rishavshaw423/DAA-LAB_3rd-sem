# coin_toss_simulation.c

Here's a walkthrough of what the code does:

**`tossCoin()`**: Simulates a single coin toss with a given bias probability. Generates a random number between 0 and 1, and returns `1` (heads) if it's less than `biasProbability`, else `0` (tails). Passing `0.5` gives a fair coin.

**`main()`**:

1. **Get inputs**: Prompts for `totalTosses` (how many tosses to simulate) and `biasProbability` (the target probability of heads for the biased coin, e.g. `0.7`). Validates that the bias is between 0 and 1.

2. **Set up tracking**: Allocates two arrays, `fairProb` and `biasedProb`, to store the *running* probability of heads after each toss (this is what makes the convergence graph possible).

3. **Run the simulation**: Loops through `totalTosses` tosses. On each iteration:
   - Tosses a fair coin (`p=0.5`) and a biased coin (`p=biasProbability`) independently
   - Updates the running heads counts for each
   - Records the running probability (`heads so far / tosses so far`) for both coins at that point

4. **Print final results**: Displays the final observed probability of heads for both coins after all tosses.

5. **Plot with GNUplot**: Opens a pipe to `gnuplot -persistent` and sets up the graph (title, axis labels, grid, log-scale x-axis, fixed y-range of `[0,1]`). Plots four series:
   - The fair coin's running probability over time
   - The biased coin's running probability over time
   - A dashed reference line at `0.5` (expected value for the fair coin)
   - A dashed reference line at `biasProbability` (expected value for the biased coin)

6. **Cleanup**: Closes the GNUplot pipe and frees the allocated arrays.

Essentially: this is a Law of Large Numbers demo — it simulates two coins toss-by-toss, tracks how their observed heads-probability evolves, and plots both curves converging toward their true expected probabilities as the number of tosses grows (the log-scale x-axis makes the early, noisy convergence easier to see).