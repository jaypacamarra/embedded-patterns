/* 
* This is a demo program showcasing the virtual api pattern
* implemented in Martin K. Schroder's video
* https://www.youtube.com/watch?v=37VfAZKeHu0
*
* The implementation of the virtual api pattern comprises of
* 3 parts:
*
* 1. API Interface
*
* 	This is the traits definition. The API data structure
* 	is only shared between the generic api and the 
* 	implementations of this interface. Thus this is a 
* 	project private API not exposes to the outside because
* 	we want to actively prevent other code from changing it
* 	since it would break the pattern.
*
* 	see files: serial_ops.h
*
* 2. Generic API
*
* 	This part is exposed outside of your library. All the
* 	member functions of this interface operate on pointer
* 	to pointer of the API interface meaning that the data
* 	structure itself only needs to be declared but does
* 	not need to be defined in the public interface.
*
* 	see files: serial.h, serial.c
*
* 3. Implementation
*
* 	This is the concrete implementation. It ONLY depends on
* 	shared API all other aspects of the implementation are
* 	hidden. You will have to use Opaque pattern here or have
* 	some other way to register the abstract interface pointer
* 	so that the application can query it (for example by 
* 	maintaining a list of all implementations indexed by a
* 	string or an enum - or through dynamic allocation).
* 	For other platform specific implementation, for example
* 	serial_stm32_impl.h/.c to implement a serial interface
* 	for STM32 specific line of MCUs.
*
* 	see files: serial_x86_impl.h, serial_x86_impl.c
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
