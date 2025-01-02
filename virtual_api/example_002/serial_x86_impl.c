#include "serial.h"
#include "serial_x86_impl.h"
#include "serial_ops.h"
#include <stdio.h>
#include <string.h>

/*
 * What the CONTAINER_OF macro does:
 *
 * It obtains a pointer to the container structure that contains a given member
 * essentially giving you the address of the outer structure from a pointer to 
 * one of its members
 *
 * ptr: pointer to the member of the structure
 * type: the type of the outer container structure
 * member: the name of the member within the structure
 */
#define CONTAINER_OF(ptr, type, member)                                        \
  ((type *)((char *)(ptr) - offsetof(type, member)))

static int serial_impl_write(const struct serial_ops **handle, const char *data,
                             size_t size) {
  // here we can resolve concrete type in the usual type safe way
  struct serial_x86_impl *self = CONTAINER_OF(handle, struct serial_x86_impl, serial);
  // just print a simple message
  printf("write: %s", data);
  return size;
}

static int serial_impl_read(const struct serial_ops **handle, const char *data,
                            size_t size) {
  // Similar read implementation here
  return -1;
}

static const struct serial_ops _ops = {
	.write = serial_impl_write,
	.read = serial_impl_read
};

void serial_impl_init(struct serial_x86_impl *self) {
  memset(self, 0, sizeof(*self));
  self->serial = &_ops;
}

const struct serial_ops **serial_impl_to_serial(struct serial_x86_impl *self) {
  return &self->serial;
}
