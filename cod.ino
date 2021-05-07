#include <Keyboard.h>

const int SW_pin = 2; 
const int X_pin = A0;
const int Y_pin = A3; 
int x, y;
void setup() 
{
  pinMode(SW_pin, INPUT); 
  digitalWrite(SW_pin, HIGH); 
  Serial.begin(115200);
  Keyboard.begin();
}
void loop() 
{
  x = analogRead(X_pin); 
  if (x == 1023) 
  {
    Serial.println("Up:");
    Keyboard.press(218); 
  }
  else
  {
    Keyboard.release(218);  
  }
  x = analogRead(X_pin);  
  if (x == 0) 

  {
    Serial.println("Down:");
    Keyboard.press(217); 
  }
  else
  {
    Keyboard.release(217);  
  }
  y = analogRead(Y_pin);  

    if (y == 1023) 
    {
      Serial.println("Right:"); 
      Keyboard.press(216); 
    }
    else
    {
     Keyboard.release(216);  
    }
  y = analogRead(Y_pin); 

    if (y == 0) 
    {
      Serial.println("Left:");
      Keyboard.press(215); 

  }
  else
  {
    Keyboard.release(215);  
  }
  int z = digitalRead(SW_pin); 
    if (z == 0)
    {
      Serial.println("Enter:");
       Keyboard.println(); //enter key is pressed
   }
  delay(500);
}
