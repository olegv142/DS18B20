#pragma once

#include <stdint.h>

class OneWire;

/*
 * Simple API for reading single thermometer
 */
class DS18B20 {
public:
	DS18B20(OneWire& w) : m_w(w) {}

	// Check thermometer is connected.
	// The rom[1..6] will contain unique device id on output
	bool probe(uint8_t rom[8]);

	// Start temperature reading. It takes 750 msec to complete.
	bool convert();

	// Read temperature in 12.4 fixed point format
	bool read(int16_t& v);

private:
	OneWire& m_w;
};
