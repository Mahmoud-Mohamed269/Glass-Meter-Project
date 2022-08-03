
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
int Reading=0;
float volt=0.00;
float Sum;
float current =0.00;
String str_volt , str_current;
//float Power;
// Define output strings 
String str_out;
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
void setup() {
  // Initialize ASK Object
  rf_driver.init();
Serial.begin(9600);
 pinMode (A0,INPUT);}
void loop()
{ Sum=0.0;
  for(int i=0;i<100;i++){
  Reading=analogRead(A0);
  volt=Reading*4.86E-3;
  Sum=Sum+volt;}
  volt=Sum/100.0;
  current=(( volt-2.5)/0.185);
/* Power=12.0*current;
Serial.print("Power=");
Serial.print(Power);
Serial.print("watt");
Serial.print("\t");*/
    str_volt = String(volt);
    str_current = String(current);
    str_out = str_volt + "V" + "," + str_current + "A" ;
    // Compose output character
    static char *msg = str_out.c_str();
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
Serial.println(str_out);
    delay(600);
}
