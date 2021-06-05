#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"


static uint16_t ledsVirtuales;



void setUp(void) {

   Leds_Create(&ledsVirtuales);

}



void tearDown(void) {

}



void test_LedsOffAfterCreate(void) {

   uint16_t ledsVirtuales = 0xFFFF;

   Leds_Create(&ledsVirtuales);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_HEX16);

}



void test_TurnOnLedOne(void) {

   Leds_TurnOn(1);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_HEX16);

}



void test_TurnOffLedOne(void) {

   Leds_TurnOn(1);

   Leds_TurnOff(1);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_HEX16);

}



void test_TurnOnMultipleLeds(void) {

   Leds_TurnOn(8);

   Leds_TurnOn(9);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0180)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_HEX16);

}



void test_TurnOffAnyLed(void) {

   Leds_TurnAllOn();

   Leds_TurnOff(8);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFF7F)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_HEX16);

}



void test_TurnAllOn(void) {

   Leds_TurnAllOn();

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_HEX16);

}



void test_LedMemoryIsNotReadable(void) {

   ledsVirtuales = 0xFFFF;

   Leds_TurnOn(8);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0080)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_HEX16);

}



void test_TurnOffMultipleLeds(void)

{

   Leds_TurnAllOn();

   Leds_TurnOff(8);

   Leds_TurnOff(9);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFE7F)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_HEX16);

}



void test_TurnAllOff(void)

{

   Leds_TurnAllOn();

   Leds_TurnAllOff();

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_HEX16);

}



void test_QueryLedState_On(void)

{

   uint8_t aux;

   Leds_TurnOn(7);

   Leds_TurnOn(2);

   Leds_TurnOn(4);

   aux = Leds_isOn(4);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((1)), (UNITY_INT)(UNITY_INT8 )((aux)), (

  ((void *)0)

  ), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_HEX8);

}



void test_QueryLedState_Off(void)

{

   uint8_t aux;

   Leds_TurnAllOn();

   Leds_TurnOff(4);

   aux = Leds_isOn(4);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((aux)), (

  ((void *)0)

  ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_HEX8);

}



void test_CheckLimits(void)

{

   Leds_TurnAllOn();

   Leds_TurnOff(17);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_HEX16);



   Leds_TurnAllOff();

   Leds_TurnOn(17);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_HEX16);



   uint8_t aux;

   aux = Leds_isOn(17);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(99), UNITY_DISPLAY_STYLE_HEX16);

}
