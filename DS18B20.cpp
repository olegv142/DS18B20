#include "DS18B20.h"
#include <OneWire.h>

bool DS18B20::probe(uint8_t rom[8])
{
	if (!m_w.reset())
		return false;
	m_w.write(0x33);
	m_w.read_bytes(rom, 8);
	return rom[0] == 0x28 && OneWire::crc8(rom, 7) == rom[7];
}

bool DS18B20::convert()
{
	if (!m_w.reset())
		return false;
	m_w.write(0xcc);
	m_w.write(0x44);
	return true;
}

bool DS18B20::read(int16_t& v)
{
	uint8_t buff[9];
	if (!m_w.reset())
		return false;
	m_w.write(0xcc);
	m_w.write(0xbe);
	m_w.read_bytes(buff, 9);
	v = (int16_t)buff[0] | ((int16_t)buff[1] << 8);
	return OneWire::crc8(buff, 8) == buff[8];
}
