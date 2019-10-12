#pragma once

#define FLOAT_MIN		1.175494e-38				// Minimum floating-point value
#define FLOAT_MAX		3.402823e+38				// Maximum floating-point value
#define FLOAT_EPSILON	1.192093e-07				// Smallest possible floating-point value

#define DOUBLE_MAX		1.797693e+308				// Maximum possible double-precision floating-point value

#define SHORT_MIN    (-32768)						// Minimum (signed) short value
#define SHORT_MAX      32767						// Maximum (signed) short value
#define USHORT_MAX     0xffff						// Maximum unsigned short value

#define INT_MIN     (-2147483647 - 1)				// Minimum (signed) int value
#define INT_MAX       2147483647					// Maximum (signed) int value

#define UINT_MAX      0xffffffff					// Maximum unsigned int value

#define LONG_MIN    (-2147483647L - 1)				// Minimum (signed) long value
#define LONG_MAX      2147483647L					// Maximum (signed) long value

#define ULONG_MAX     0xffffffffUL					// Maximum unsigned long value

#define LLONG_MAX     9223372036854775807i64		// Maximum signed long long int value
#define LLONG_MIN   (-9223372036854775807i64 - 1)	// Minimum signed long long int value
#define ULLONG_MAX    0xffffffffffffffffui64		// Maximum unsigned long long int value

#define INT8_MIN     (-127i8 - 1)					// Minimum signed 8 bit value
#define INT8_MAX       127i8						// Maximum signed 8 bit value
#define UINT8_MAX      0xffui8						// Maximum unsigned 8 bit value

#define INT16_MIN    (-32767i16 - 1)				// Minimum signed 16 bit value
#define INT16_MAX      32767i16						// Maximum signed 16 bit value
#define UINT16_MAX     0xffffui16					// Maximum unsigned 16 bit value

#define INT32_MIN    (-2147483647i32 - 1)			// Minimum signed 32 bit value
#define INT32_MAX      2147483647i32				// Maximum signed 32 bit value
#define UINT32_MAX     0xffffffffui32				// Maximum unsigned 32 bit value

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

#define DEG2RAD(X) (X / 180.0 * PI)
#define RAD2DEG(X) (X * 180.0 / PI)