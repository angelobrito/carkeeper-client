/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/

#define OIL_PLUG 11
#define AIR_FILTER 12
#define OIL_RESERVOIR 10
#define OIL_FILTER 8
#define FUEL_FILTER 9

#include <string.h>

void report_state(String sensor, bool state) {
  Serial.print("{" + sensor + "," + state + "}\n");
}

void get_state_oil_plug()
{
  static bool state_oil_plug = false;
  if (digitalRead(OIL_PLUG))
  {
    if (!state_oil_plug)
    {
      state_oil_plug = true;
      report_state("OilPlug", state_oil_plug);
    }
  }
  else
  {
    if (state_oil_plug)
    {
      state_oil_plug = false;
      report_state("OilPlug", state_oil_plug);
    }
  }
}

void get_state_air_filter()
{
  static bool state_air_filter = false;
  if (digitalRead(AIR_FILTER))
  {
    if (!state_air_filter)
    {
      state_air_filter = true;
      report_state("AirFilter", state_air_filter);
    }
  }
  else
  {
    if (state_air_filter)
    {
      state_air_filter = false;
      report_state("AirFilter", state_air_filter);
    }
  }
}

void get_state_oil_reservoir()
{
  static bool state_oil_reservoir = false;
  if (digitalRead(OIL_RESERVOIR))
  {
    if (!state_oil_reservoir)
    {
      state_oil_reservoir = true;
      report_state("OilReservoirScrewCap", state_oil_reservoir);
    }
  }
  else
  {
    if (state_oil_reservoir)
    {
      state_oil_reservoir = false;
      report_state("OilReservoirScrewCap", state_oil_reservoir);
    }
  }
}

void get_state_oil_filter()
{
  static bool state_oil_filter = false;
  if (digitalRead(OIL_FILTER))
  {
    if (!state_oil_filter)
    {
      state_oil_filter = true;
      report_state("OilFilter", state_oil_filter);
    }
  }
  else
  {
    if (state_oil_filter)
    {
      state_oil_filter = false;
      report_state("OilFilter", state_oil_filter);
    }
  }
}

void get_state_fuel_filter()
{
  static bool state_fuel_filter = false;
  if (digitalRead(FUEL_FILTER))
  {
    if (!state_fuel_filter)
    {
      state_fuel_filter = true;
      report_state("FuelFilter", state_fuel_filter);
    }
  }
  else
  {
    if (state_fuel_filter)
    {
      state_fuel_filter = false;
      report_state("FuelFilter", state_fuel_filter);
    }
  }
}

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  delay(1000);
  //Serial.println("Start test");
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(OIL_PLUG, INPUT);
  pinMode(AIR_FILTER, INPUT);
  pinMode(OIL_RESERVOIR, INPUT);
  pinMode(OIL_FILTER, INPUT);
  pinMode(FUEL_FILTER, INPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  get_state_oil_plug();
  get_state_air_filter();
  get_state_oil_reservoir();
  get_state_oil_filter();
  get_state_fuel_filter();
}
