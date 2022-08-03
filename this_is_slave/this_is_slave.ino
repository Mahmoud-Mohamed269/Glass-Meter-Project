//this is slave

int state = 0;
const int led = 8;
const int button = 2;
int buttonstate = 1;

void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);
}
void loop() 
{
 if(Serial.available() > 0)
 { 
    // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
 
 // Reading the button
 buttonstate = digitalRead(button);
 if (buttonstate == LOW) 
 {
   Serial.write('1'); // Sends '1' to the master to turn on LED
 }
 else
 {
   Serial.write('0');
 }  

  if (state == '1') 
 {
  digitalWrite(led, HIGH); // LED ON
  state = 0;
 }
 else if (state == '0') 
 {
  digitalWrite(led, LOW); // LED ON
  state = 0;
 }
}
