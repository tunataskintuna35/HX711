#include "HX711.h"

// HX711.DOUT	- pin #A1
// HX711.PD_SCK	- pin #A0

HX711 scale(A1, A0);		// parameter "gain" is ommited; the default value 128 is used by the library

void setup() {
  Serial.begin(38400);
  

 

 	

  
scale.read_average(20);	

  
scale.get_value(5);		// print the average of 5 readings from the ADC minus the tare weight (not set yet)

 
  scale.get_units(5);	// print the average of 5 readings from the ADC minus tare weight (not set) divided 
						// by the SCALE parameter (not set yet)  

  scale.set_scale(2280.f);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();				        // reset the scale to 0

  

  
  Serial.println(scale.read());                 // print a raw reading from the ADC

 
  Serial.println(scale.read_average(20));       // print the average of 20 readings from the ADC

  
  	scale.get_value(5)		

  
	scale.get_units(5)        // print the average of 5 readings from the ADC minus tare weight, divided 
						// by the SCALE parameter set with set_scale

  Serial.println("Readings:");
}

void loop() {
  Serial.print("one reading:\t");
  

  scale.power_down();			        // put the ADC in sleep mode
  delay(5);
  scale.power_up();
}
