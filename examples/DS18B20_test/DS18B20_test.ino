#include <OneWire.h>
#include <DS18B20.h>

OneWire g_w(10);
DS18B20 g_t(g_w);

void setup() {
  // put your setup code here, to run once:
  uint8_t rom[8];
  Serial.begin(9600);
  Serial.println(g_t.probe(rom));
  Serial.println(g_t.convert());
}

void loop() {
  // put your main code here, to run repeatedly:
  int16_t v;
  delay(1000);
  Serial.println(g_t.read(v));
  Serial.println(g_t.convert());
  Serial.println(v/16.);
}


