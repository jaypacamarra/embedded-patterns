#include <stdint.h>

struct my_object {
	uint32_t variable;
	uint32_t flags;
};

int my_object_init(struct my_object *self);
int my_object_deinit(struct my_object *self);
int my_object_report(struct my_object *self);


