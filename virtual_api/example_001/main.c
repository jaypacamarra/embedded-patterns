#include <stdio.h>
#include <stdint.h>

/*
 * This program implements the Virtual API design pattern
 *
 * description:
 * The virtual API design pattern. sometimes called the virtual
 * function table (VFT) pattern is a valuable technique in 
 * embedded c programming for providing a common interface
 * to different implementations of the same functionality
 *
 * What is a VTable?
 * It is essentially a table (array) of function pointers that
 * map a set of "virtual functions" to their implementations
 * for a particular object or type.o
 *
 * Example of an abstract interface (virtual function table)
 * typedef struct {
 * 	void (*start)(void);
 * 	void (*stop)(void);
 * } DeviceVTable;
 *
 * Definition of a Base object
 * typedef struct {
 * 	const DeviceVTable *vtable; // pointer to the VTable
 * } Device;
 */


// Implementation 1
void start_motor_old() {
	printf("Motor old started\n");
}
void stop_motor_old() {
	printf("Motor old stopped\n");
}

// Implementation 2
void start_motor_new() {
	printf("motor new started\n");
}
void stop_motor_new() {
	printf("motor new stopped\n");
}

typedef struct {
    	void (*start)(void);
    	void (*stop)(void);
} DeviceVTable;

typedef struct {
	const DeviceVTable *vtable; // pointer to the VTable
} Device;

// VTables for each implementaion
const DeviceVTable MotorOldVTable = {start_motor_old, stop_motor_old};
const DeviceVTable MotorNewVTable = {start_motor_new, stop_motor_new};


// Initialize devices with their respective VTables
Device motor_old = { &MotorOldVTable };
Device motor_new = { &MotorNewVTable };

void start_device(Device *device) {
	if (device && device->vtable && device->vtable->start) {
		device->vtable->start();

	}
}

void stop_device(Device *device) {
	if (device && device->vtable && device->vtable->stop) {
		device->vtable->stop();
	}
}

int main(void) {
	start_device( &motor_old );
	stop_device( &motor_old );

	start_device( &motor_new );
	stop_device( &motor_new );

	return 0;
}
