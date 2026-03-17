#include "circular_buffer.h"
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>

circular_buffer_t *new_circular_buffer(size_t capacity) 
{
    if (capacity == 0) return NULL;
    circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));
    if (buffer == NULL) return NULL;
    buffer->buffer = malloc(capacity * sizeof(buffer_value_t));
    if (buffer->buffer == NULL) {
        free(buffer);
        return NULL;
    }
    buffer->capacity = capacity;
    buffer->head = 0;
    buffer->tail = 0;
    buffer->size = 0;
    return buffer;
}
int16_t write(circular_buffer_t *buffer, buffer_value_t value) 
{
    if (buffer->size == buffer->capacity) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }
    buffer->buffer[buffer->head] = value;
    buffer->head = (buffer->head + 1) % buffer->capacity;
    buffer->size++;
    return EXIT_SUCCESS;
}
int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value) 
{
    if (buffer->size == 0) {
        errno = ENODATA;
        return EXIT_FAILURE;
    } 
    *read_value = buffer->buffer[buffer->tail];
    buffer->tail = (buffer->tail + 1) % buffer->capacity;
    buffer->size--;
    return EXIT_SUCCESS;
}
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
    
    buffer->buffer[buffer->head] = value;
    buffer->head = (buffer->head + 1) % buffer->capacity;
    if (buffer->size == buffer->capacity) {
        buffer->tail = (buffer->tail + 1) % buffer->capacity;
    }
    else {
        buffer->size++;
    }
    return EXIT_SUCCESS;
}
void clear_buffer(circular_buffer_t *buffer) 
{
    buffer->size = 0;
    buffer->tail = 0;
    buffer->head = 0;
}
void delete_buffer(circular_buffer_t *buffer) 
{
    free(buffer->buffer);
    free(buffer);
}
