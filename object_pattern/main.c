#include "my_object.h"

#define DUMMY_VARIABLE 	460
#define DUMMY_FLAGS	0xfeaa01ce

int main(void) {
	// allocate an object
	struct my_object obj1;

	// initialize object, which zeros out all fields
	my_object_init(&obj1);

	// assign object members valid data
	obj1.variable = DUMMY_VARIABLE;
	obj1.flags = DUMMY_FLAGS;

	// call report function to print all member data
	my_object_report(&obj1);

	return 0;
}
