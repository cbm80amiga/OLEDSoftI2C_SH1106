// (C)2016-18 Pawel A. Hernik

//#include <OLEDSoftI2C_SSD1306.h>
#include <OLEDSoftI2C_SH1106.h>
// define USEHW in above header for hw I2C version

//OLEDSoftI2C_SSD1306 oled(0x3c);
OLEDSoftI2C_SH1106 oled(0x3c);

#if USEHW==1
#include <Wire.h>
#endif

//#include "fonts_all.h"
#include "small5x7bold_font.h"
#include "term8x14_font.h"
#include "digits4x7_font.h"

const uint8_t npn [] PROGMEM = {28,4,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10,
0x10, 0x10, 0x10, 0x20, 0x20, 0xA0, 0x40, 0xA0, 0x10, 0x0F, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80,
0xE0, 0x9C, 0x82, 0x81, 0x80, 0x80, 0x80, 0x80, 0xFE, 0xFE, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02,
0x01, 0x00, 0x00, 0x00, 0x01, 0x02, 0x1C, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0x40, 0x80,
0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x02, 0x04, 0x08, 0x90, 0xA0, 0xC0, 0xF0, 0x00, 0x00, 0x00,
0x80, 0x40, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04,
0x04, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x05, 0x02, 0x05, 0x08, 0xF0, 0x00, 0x00
};

const uint8_t ind [] PROGMEM = {27,1,
0x40, 0x40, 0x40, 0x78, 0x04, 0x02, 0x02, 0x04, 0x78, 0x04, 0x02, 0x02, 0x04, 0x78, 0x04, 0x02,
0x02, 0x04, 0x78, 0x04, 0x02, 0x02, 0x04, 0x78, 0x40, 0x40, 0x40, 
};

void setup() 
{
  Serial.begin(9600);
  oled.init();
}

char buf[40];
void loop() 
{
  oled.clrScr();
  oled.setFont(Small5x7PLBold);
  oled.setDigitMinWd(8);
  oled.printStr(0, 0, "ąćęłóśźż 123");
  oled.printStr(0, 1, "ĄĆĘŁÓŚŹŻ 123");
  oled.setDigitMinWd(6);
  oled.printStr(0, 2, "1234567890123");
  oled.setFontMinWd(5);
  oled.printStr(0, 3, "abAwij1234");
  oled.setFontMinWd(0);
  oled.printStr(0, 4, "abAwij1234");
  oled.setDigitMinWd(0);
  oled.printStr(0, 5, "abAwij1234");
  delay(5000);
  
  oled.clrScr();
  oled.setFont(Term8x14PL);
  oled.printStr(42, 3, "Żółw1");
  oled.drawBitmap(npn, 3, 0);
  oled.drawBitmap(ind, 11, 5);
  oled.fillWin(60,0,20,2,0xaa);
  oled.setFont(Small5x7PLBold);
  oled.printStr(0,2,"B");
  oled.printStr(30,0,"E");
  oled.printStr(30,3,"C");
  oled.printStr(5,5,"0");
  oled.printStr(40,5,"1");
  oled.setFont(Digits4x7);
  oled.setDigitMinWd(4);
  
  for(int i=0; i<300; i++) {
    snprintf(buf,39,"%06d",random(1,1000000));
    oled.printStr(55,5,buf);
    delay(150);
  }
}
