
#include <RH_ASK.h>
#include <SPI.h> 
String str_out , str_current , str_volt;
RH_ASK rf_driver;
#include<U8glib.h> 
U8GLIB_SSD1306_128X64 u8g(13, 11, 10, 9, 8);    
// 13 - SCL // 11 - SDA // 8 - RES // 9 - DC 

void draw(void) {// graphic commands to redraw the complete screen should be placed here  
//u8g.setFont(u8g_font_unifont);
u8g.setFont(u8g_font_gdr20);
u8g.setFontRefHeightExtendedText();
u8g.drawStr( 0, 22, "volt="); 
u8g.setPrintPos(45,22);
 u8g.print( str_volt );
 u8g.drawStr( 0, 42, "Current="); 
u8g.setPrintPos(65,42);
 u8g.print( str_current );}

void setup() { // Initialize ASK Object
  rf_driver.init();
Serial.begin(9600);
// flip screen, if required
  // u8g.setRot180();
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);
  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);   }  // white
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);   }      // max intensity
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);  }       // pixel on
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);} 
  pinMode(8, OUTPUT);}

void loop()
{// Set buffer to size of expected message
    uint8_t buf[11];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    { str_out = String((char*)buf);
      for (int i = 0; i < str_out.length(); i++) {
      if (str_out.substring(i, i+1 ) == ",") {
      str_volt = str_out.substring(0, i);
      str_current = str_out.substring(i+2);
    break;}} // picture loop
  {u8g.firstPage();  
  do {draw();
  } while( u8g.nextPage() );}
  // rebuild the picture after some delay
 // delay(20);
    }}
