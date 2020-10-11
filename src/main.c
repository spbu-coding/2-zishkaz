#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>
//#include "choose_sort.c"

short args_solve(int argc, char **argv, long long *from, long long *to) {

    if(argc <= 1) return -1;
    if(argc > 3) return -2;
    if(argc > 2 && strchr(argv[1], '=') == NULL && strchr(argv[2], '=') == NULL) return -4;
    char *temp1, *temp2;
    unsigned opt_len;
    if(strchr(argv[1], '=') != NULL) {

        opt_len = strlen(argv[1]) - strlen(strchr(argv[1], '=')) + 1;
        if (opt_len < strlen(argv[1])) {

            temp1 = malloc(sizeof(char) * opt_len);
            strncpy(temp1, argv[1], opt_len);
            temp1[opt_len] = '\0';
            char *buf_string;
            long long buf_int = 0;
            buf_string = malloc(sizeof(char) * strlen(argv[1]) - opt_len);
            buf_string = strchr(argv[1], '=') + 1;
            if (buf_string[0] >= 49 && buf_string[0] <= 57 || buf_string[0] == '-')
                buf_int = strtoll(buf_string, &buf_string, 10);
            if (!strcmp(temp1, "--from=")) {

                if (strlen(buf_string) == 0) *from = buf_int; else *from = 0;
            } else if (!strcmp(temp1, "--to=")) {

                if (strlen(buf_string) == 0) *to = buf_int; else *to = 0;
            }
        } else {

            if (strcmp(argv[1], "--from=") == 0) *from = 0;
            if (strcmp(argv[1], "--to=") == 0) *to = 0;
        }
    }
    if(argc < 3 || strchr(argv[2], '=') == NULL) return 0;
    opt_len = strlen(argv[2]) - strlen(strchr(argv[2], '=')) + 1;
    if(opt_len < strlen(argv[2])) {

        temp2 = malloc(sizeof(char) * opt_len);
        strncpy(temp2, argv[2], opt_len);
        temp2[opt_len] = '\0';
        char *buf_string;
        long long buf_int;
        buf_string = malloc(sizeof(char) * (strlen(argv[2]) - opt_len));
        buf_string = strchr(argv[2], '=') + 1;
        if(buf_string[0] >= 49 && buf_string[0] <= 57 || buf_string[0] == '-')  buf_int = strtoll(buf_string, &buf_string, 10);
        if(!strcmp(temp2, "--from=")) {

            if(strlen(buf_string) == 0) *from = buf_int; else *from = 0;
        } else if(!strcmp(temp2, "--to=")) {

            if(strlen(buf_string) == 0) *to = buf_int; else *to = 0;
        }
    } else {

        if(strcmp(argv[2], "--from=") == 0) *from = 0;
        if(strcmp(argv[2], "--to=") == 0) *to = 0;
    }
    if(*from > *to || *from == LLONG_MIN && *to == LLONG_MAX) return -4;
    if(!strcmp(temp1, temp2)) return -3;
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
    realloc(&array, sizeof(long long) * elems_count);
    unsigned counter = 0;
    for(unsigned i = 0; i < elems_count;i++) {

        if(array[i] > sort_from && array[i] < sort_to) counter++;
    }
    long long *array_reduced = malloc(sizeof(long long) * counter);
    counter = 0;
    for(unsigned i =0; i< elems_count;i++) {

        if(array[i] > sort_from && array[i] < sort_to) {

            array_reduced[counter] = array[i];
            counter++;
        } else {

            if(array[i] <= sort_from) fprintf(stdout, "%lld ", array[i]);
            if(array[i] >= sort_to) fprintf(stderr, "%lld ", array[i]);
        }
    }
    unsigned swapped_count = 0;
    if(counter > 0) swapped_count = choose_sort(array_reduced, counter);
    free(array);
    free(array_reduced);
    return swapped_count;
}
