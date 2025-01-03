#ifndef SERIAL_OPS_
#define SERIAL_OPS_

#include <stddef.h>

// 1. Trait Definition
//    Define Serial API
//    You can typedef const struct serial_ops ** to serial_t if you want
struct serial_ops {
	int (*write)(const struct serial_ops ** handle, const char *data, size_t size);
	int (*read)(const struct serial_ops ** handle, const char *data, size_t size);
};


#endif /* SERIAL_OPS_ */
