#ifndef SERIAL_
#define SERIAL_

/*
 * These functions are the generic trait API definitions
 */

#include <stddef.h>

struct serial_ops;

int serial_write(const struct serial_ops ** handle, const char *data, size_t size);
int serial_read(const struct serial_ops ** handle, const char *data, size_t size);

#endif
