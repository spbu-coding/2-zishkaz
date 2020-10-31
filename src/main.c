#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>

unsigned choose_sort(long long *, unsigned);

short args_solve(int argc, char **argv, long long *from, long long *to) {


    long long from_value = 0, to_value = 0, from_num = 0, to_num = 0;
    if (argc < 2) {
        return -1;
    } else if (argc > 3) {
        return -2;
    }
    for (int i = 0; i < argc; i++) {
        if (strncmp(argv[i], "--from=", strlen("--from=")) == 0) {
            from_value = strtoll(argv[i] + strlen("--from="), NULL, 10);
            from_num += 1;
        } else if (strncmp(argv[i], "--to=", strlen("--to=")) == 0) {
            to_value = strtoll(argv[i] + strlen("--to="), NULL, 10);
            to_num += 1;
        }
    }
    if (from_num > 1 || to_num > 1) {
        return -3;
    } else if (from_num == 0 && to_num == 0) {
        return -4;
    }
    if(from_num == 1) *from = from_value;
    if(to_num == 1) *to = to_value;
    return 0;
}

int main(int argc, char **argv) {
    
    long long sort_from = LLONG_MIN, sort_to = LLONG_MAX;
    int error_value = args_solve(argc, argv, &sort_from, &sort_to);
    if(error_value) return error_value;
    long long *array = malloc(sizeof(long long) * 100);
    char divider = ' ';
    unsigned elems_count = 0;
    while(divider == ' ') {

        scanf("%lld%c", &array[elems_count], &divider);
        elems_count++;
    }
    unsigned counter = 0;
    for(unsigned i = 0; i < elems_count; i++) {

        if(array[i] > sort_from && array[i] < sort_to) counter++;
    }
    long long *array_reduced = malloc(sizeof(long long) * counter);
    counter = 0;
    for(unsigned i = 0; i < elems_count; i++) {

        if(array[i] > sort_from && array[i] < sort_to) {

            array_reduced[counter] = array[i];
            counter++;
        } else {

            if(array[i] <= sort_from) fprintf(stdout, "%lld ", array[i]);
            if(array[i] >= sort_to) fprintf(stderr, "%lld ", array[i]);
        }
    }

    unsigned swapped_count = 0;
    if(counter > 0 && (sort_to > sort_from)) swapped_count = choose_sort(array_reduced, counter);
    free(array);
    free(array_reduced);
    return swapped_count;
}
