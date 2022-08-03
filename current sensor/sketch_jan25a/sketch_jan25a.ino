//Measuring Current Using ACS712
const int analogchannel = A0; //Connect current sensor with A0 of Arduino
float sensitivity = 0.185; // use 100 for 20A Module and 66 for 30A Module
float adcvalue= 0 , ave;
float offsetvoltage = 2.5; 
float Voltage , sum=0.0; 
float current;// Current measuring
//float Power; 
void setup() {
 //baud rate
 Serial.begin(9600);}
void loop() //method to run the source code repeatedly
{for(int i=0 ; i<10 ; i++)
{adcvalue = analogRead(analogchannel);//reading the value from the analog pin
 adcvalue=(adcvalue/1023.0)*5.0;
 Voltage=adcvalue;
 current =abs((Voltage - offsetvoltage)/sensitivity);
 sum+=current;}
 ave=sum/10.0;
/* Power=12.0*current;
Serial.print("Power=");
Serial.print(Power);
Serial.print("watt");
Serial.print("\t");*/
Serial.print("current=");
Serial.print(ave);
Serial.println("A");
delay(1000);}
