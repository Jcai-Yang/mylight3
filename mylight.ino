#include <Wire.h>
// GY-30
// BH1750FVI
// in ADDR 'L' mode 7bit addr
#define ADDR 0b0100011
// addr 'H' mode
// #define ADDR 0b1011100
int redPin= 7;
int greenPin = 6;
int bluePin = 5;

void setup() {
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
Serial.begin(9600); 
 while (!Serial) {   
; // wait for serial port to connect. Needed for Leonardo only 
}
Wire.begin();  
Wire.beginTransmission(ADDR); 
Wire.write(0b00000001);
Wire.endTransmission();
}

void loop() {
setColor(255, 0, 0); // Red Color
delay(1000);
setColor(0, 255, 0); // Green Color
delay(1000);
setColor(0, 0, 255); // Blue Color
delay(1000);
setColor(255, 255, 255); // White Color
delay(1000);
setColor(170, 0, 255); // Purple Color
delay(1000);
int val = 0;  
// reset
Wire.beginTransmission(ADDR); 
Wire.write(0b00000111);
Wire.endTransmission();  
Wire.beginTransmission(ADDR);  
Wire.write(0b00100000); 

Wire.endTransmission();
delay(120); 
Wire.requestFrom(ADDR, 2);  
for (val = 0; Wire.available() >= 1; ) {   
char c = Wire.read();  
 //Serial.println(c, HEX); 
val = (val << 8) + (c & 0xFF); 
}
  val = val / 1.2; 
Serial.print("lx: "); 
 Serial.println(val);
 Serial.println("OK");
  delay(100);
}
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
