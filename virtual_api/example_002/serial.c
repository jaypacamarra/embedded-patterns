#include "serial.h"
#include "serial_ops.h"

int serial_write(const struct serial_ops ** handle, const char *data, size_t size) {
	// here we DO have access to the api so we can use it directly
	return (*handle)->write(handle, data, size);
}

int serial_read(const struct serial_ops ** handle, const char *data, size_t size) {
	// here we DO have access to the api so we can use it directly
	return (*handle)->read(handle, data, size);
}
