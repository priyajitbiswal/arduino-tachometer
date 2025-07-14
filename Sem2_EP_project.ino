#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int x = 0;
int input = A0;
int state = 0;
long pt=millis();
long ct=0;
int rev=0;
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init(); // initialize the lcd

  // Print a message to the LCD.
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  Tachometer (WC) ");
  lcd.setCursor(0, 1);
  lcd.print(x);
  lcd.print("     =RPM  ");
}
void loop()
{
  ct=millis();
  int counter = digitalRead(A0);
  if (state == 0)
  {
    switch (counter) {

      case 1 : state = 1; x = x + 1; break;
      case 0 : state = 0; break;

    }
  }

  if (counter == LOW) {
    state = 0;
  }
  if(ct-pt>=5000)
  {
    rev=12*x/4;
    x=0;
    lcd.setCursor(0, 1);
    lcd.print(rev);
    pt=ct;
 }
}