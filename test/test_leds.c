#include "unity.h"
#include "leds.h"

static uint16_t ledsVirtuales;

void setUp(void) {
   Leds_Create(&ledsVirtuales);
}

void tearDown(void) {
}

void test_LedsOffAfterCreate(void) {
   uint16_t ledsVirtuales = 0xFFFF;
   Leds_Create(&ledsVirtuales);
   TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

void test_TurnOnLedOne(void) {
   Leds_TurnOn(1);
   TEST_ASSERT_EQUAL_HEX16(1, ledsVirtuales);
}

void test_TurnOffLedOne(void) {
   Leds_TurnOn(1);
   Leds_TurnOff(1);
   TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

void test_TurnOnMultipleLeds(void) {
   Leds_TurnOn(8);
   Leds_TurnOn(9);
   TEST_ASSERT_EQUAL_HEX16(0x0180, ledsVirtuales);
}

void test_TurnOffAnyLed(void) {
   Leds_TurnAllOn();
   Leds_TurnOff(8);
   TEST_ASSERT_EQUAL_HEX16(0xFF7F, ledsVirtuales);
}

void test_TurnAllOn(void) {
   Leds_TurnAllOn();
   TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);   
}

void test_LedMemoryIsNotReadable(void) {
   ledsVirtuales = 0xFFFF;
   Leds_TurnOn(8);
   TEST_ASSERT_EQUAL_HEX16(0x0080, ledsVirtuales);   
}

void test_TurnOffMultipleLeds(void)
{
   Leds_TurnAllOn();
   Leds_TurnOff(8);
   Leds_TurnOff(9);
   TEST_ASSERT_EQUAL_HEX16(0xFE7F, ledsVirtuales);
}

void test_TurnAllOff(void)
{
   Leds_TurnAllOn();
   Leds_TurnAllOff();
   TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);   
}

void test_QueryLedisOn(void)
{
   uint8_t aux;
   Leds_TurnOn(7);
   Leds_TurnOn(2);
   Leds_TurnOn(4);
   aux = Leds_isOn(4);
   TEST_ASSERT_EQUAL_HEX8(LED_ON, aux);
}

void test_QueryLedisOff(void)
{
   uint8_t aux;
   Leds_TurnAllOn();
   Leds_TurnOff(4);
   aux = Leds_isOn(4);
   TEST_ASSERT_EQUAL_HEX8(LED_OFF, aux);
}

void test_CheckLimits(void)
{
   Leds_TurnAllOn();
   Leds_TurnOff(17);
   TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
   
   Leds_TurnAllOff();
   Leds_TurnOn(17);
   TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);

   uint8_t aux;
   aux = Leds_isOn(17);
   TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}
