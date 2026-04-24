#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 15 

typedef struct {
    char buffer[SIZE];
    int head; // Index for writing
    int tail; // Index for reading
    int count; // Current number of elements
} CircularBuffer;

// Initialize the buffer pointers and counter
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// Check if the buffer is full
bool isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

// Check if the buffer is empty
bool isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

// Add a character to the buffer
void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n");
        return;
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE;
    cb->count++;
}

// Remove and return a character from the buffer
char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n");
        return '\0';
    }
    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count--;
    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    strcat(name, "CE-ESY");

    // Write name to buffer
    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    // Read and print from buffer
    printf("Result: ");
    while (!isEmpty(&cb)) {
        printf("%c", read(&cb));
    }
    printf("\n");

    return 0;
}
