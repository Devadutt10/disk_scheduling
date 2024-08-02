#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_REQUESTS 200

void main() {
    int num_request;
    printf("Enter the number of requests: ");
    scanf("%d", &num_request);

    int request[num_request];
    printf("Start entering the requests...\n");
    for (int i = 0; i < num_request; i++) {
        scanf("%d", &request[i]);
    }

    int initial;
    printf("Enter the initial head position: ");
    scanf("%d", &initial);

    int direction;
    printf("Enter the direction you want to start, 0 for left and 1 for right: ");
    scanf("%d", &direction);

    // Sorting the requests
    for (int i = 0; i < num_request - 1; i++) {
        for (int j = 0; j < num_request - i - 1; j++) {
            if (request[j] > request[j + 1]) {
                int temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }

    int left = 0, right = 0;
    int left_array[MAX_REQUESTS], right_array[MAX_REQUESTS];
    left_array[0] = 0;
    left++;

    for (int i = 0; i < num_request; i++) {
        if (request[i] < initial) {
            left_array[left++] = request[i];
        } else if (request[i] > initial) {
            right_array[right++] = request[i];
        }
    }
    right_array[right++] = MAX_REQUESTS-1;
    num_request += 2;

    // Sorting the left array in descending order
    /*
    for (int i = 0; i < left - 1; i++) {
        for (int j = 0; j < left - i - 1; j++) {
            if (left_array[j] < left_array[j + 1]) {
                int temp = left_array[j];
                left_array[j] = left_array[j + 1];
                left_array[j + 1] = temp;
            }
        }
    } */

    int total_head_mov = 0;
    int sequence[num_request];
    int index = 0;

    if (direction == 0) {
        for (int i = 0; i < left; i++) {
            total_head_mov += abs(initial - left_array[i]);
            initial = left_array[i];
            sequence[index++] = left_array[i];
        }
        for (int i = 0; i < right; i++) {
            total_head_mov += abs(initial - right_array[i]);
            initial = right_array[i];
            sequence[index++] = right_array[i];
        }
    } else if (direction == 1) {
        for (int i = 0; i < right; i++) {
            total_head_mov += abs(initial - right_array[i]);
            initial = right_array[i];
            sequence[index++] = right_array[i];
        }
        for (int i = 0; i < left; i++) {
            total_head_mov += abs(initial - left_array[i]);
            initial = left_array[i];
            sequence[index++] = left_array[i];
        }
    } else {
        printf("Enter a valid choice.\n");
        exit(1);
    }

    printf("The total head movement is: %d\n", total_head_mov);
    printf("The seek sequence is...\n");
    for (int i = 0; i < num_request; i++) {
        printf("%d\t", sequence[i]);
    }
    printf("\n");
}

