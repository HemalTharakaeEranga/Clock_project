#include <stdio.h>
#include <time.h>
#include <unistd.h>

void clear_screen() {
    // ANSI escape code to clear the screen
    printf("\033[H\033[J");
}

void print_time(struct tm *timeinfo) {
    // Print the time in HH:MM:SS format
    printf("%02d:%02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

int main() {
    while (1) {
        time_t rawtime;
        struct tm *timeinfo;

        // Get the current time
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        // Clear the screen
        clear_screen();

        // Print the current time
        print_time(timeinfo);

        // Sleep for one second
        sleep(1);
    }

    return 0;
}
