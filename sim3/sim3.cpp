#include <iostream>
#include <stdio.h>
#include <time.h>

// interval of each refresh in time system below
const int NUM_SECONDS = 1;

int main() {
    int count = 1;

    double time_counter = 0;

    clock_t this_time = clock();
    clock_t last_time = this_time;

    // printf("Gran = %ld\n", NUM_SECONDS * CLOCKS_PER_SEC);

    while (true) {
        this_time = clock();

        time_counter += (double) (this_time - last_time);

        last_time = this_time;

        if (time_counter > (double) (NUM_SECONDS * CLOCKS_PER_SEC)) {
            time_counter -= (double) (NUM_SECONDS * CLOCKS_PER_SEC);

            // TODO: do human actions and stuff here?
            printf("%d\n", count);
            count++;
        }

        // printf("DebugTime = %f\n", time_counter);
    }
}
