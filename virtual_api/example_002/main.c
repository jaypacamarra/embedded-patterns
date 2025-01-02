/* 
* This is a demo program showcasing the virtual api pattern
* implemented in Martin K. Schroder's video
* https://www.youtube.com/watch?v=37VfAZKeHu0
*/ 

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "serial.h"
#include "serial_x86_impl.h"

int main(void) {
	// iniitialization of implementation (usually would be done separately from usage below)
	struct serial_x86_impl serial;
	serial_impl_init(&serial);

	// get the handle that can be passed around and used with the generic api
	const struct serial_ops ** handle = serial_impl_to_serial(&serial);

	const char *data = "Hello World!\n";
	serial_write(handle, data, strlen(data));

	return 0;
}
