#include <stdio.h>
#include <string.h>
#include "my_object.h"

// for naming, prefix your function with your type of the object.
// The init and deinit functions are analogous to contructors
// and destructors in OOP langagues like c++ and are good 
// practice to implement in the object pattern.

int my_object_init(struct my_object *self) {
	// this is very important to initialize all the fields
	// and initialize a structure to sane values such as 
	// clearing all fields to 0 so you do not operate on
	// garbage values on startup
	memset(self, 0, sizeof(*self));
}

int my_object_deinit(struct my_object *self) {
	// cleanup
}

// simply prints the variables of the self pointer
int my_object_report(struct my_object *self) {
	printf("variable: %u\n", self->variable);
	printf("flag: %x\n", self->flags);
	return 0;
}
