#include<U8glib.h> 
// this is constructor , make sure you put right pin nos here.
U8GLIB_SSD1306_128X64 u8g(13, 11, 10, 9, 8);    

// 13 - SCL
// 11 - SDA
// 8 - RES
// 9 - DC
// 10- keep it open, if your display do not support chip-select option

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
  u8g.setPrintPos(0, 20); 
  // call procedure from base class, http://arduino.cc/en/Serial/Print
  u8g.print("Hello World!");
 /*
  u8g.drawStr( 0, 22, "Hello"); // to print 2  messages in the same line
 u8g.drawStr( 45, 22, "World!");
u8g.drawStr( 27, 22, "Hello"); // to print 2  messages in 2 line
 u8g.drawStr( 27, 42, "World!");*/ }

void setup(void) {
  // flip screen, if required
  // u8g.setRot180();
  
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  } 
  pinMode(8, OUTPUT);}

void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  //delay(50);
}

