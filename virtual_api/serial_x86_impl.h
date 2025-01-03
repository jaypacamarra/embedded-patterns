#ifndef SERIAL_X86_IMPL_
#define SERIAL_X86_IMPL_

#include "serial_ops.h"

struct serial_x86_impl {
	const struct serial_ops *serial;
};

void serial_impl_init(struct serial_x86_impl *self);
const struct serial_ops ** serial_impl_to_serial(struct serial_x86_impl *self);

#endif /* SERIAL_X86_IMPL_ */
