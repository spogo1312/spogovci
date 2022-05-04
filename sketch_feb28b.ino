
#define VRX A0
#define VRY A1
#define VRX2 A3
#define VRY2 A2


int tlacitko = 52;
int tlacitko2 = 50;
int tlacitko3 = 48;
int tlacitko4 = 46;
int tlacitko5 = 44;
int tlacitko6 = 42;
int red_light_pin= 26;
int green_light_pin = 28;
int nulaX, nulaY, nulaX2, nulaY2;
int x, y, x2, y2;
int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
#include <Keyboard.h>
void readJoy() {
  x = analogRead(VRX) - nulaX;
  if (x >= 0) 
    x = map(x, 0, 1023-nulaX, 0, 100);
  else
  
    x = map(x, -nulaX, 0, -100, 0);

  y = analogRead(VRY) - nulaY;
  if (y >= 0) 
    y = -map(y, 0, 1023-nulaY, 0, 100);
  else
    y = -map(y, -nulaY, 0, -100, 0);

  x2 = analogRead(VRX2) - nulaX2;
  if (x2 >= 0) 
    x2 = map(x2, 0, 1023-nulaX2, 0, 100);
  else
    x2 = map(x2, -nulaX2, 0, -100, 0);

  y2 = analogRead(VRY2) - nulaY2;
  if (y2 >= 0) 
    y2 = -map(y2, 0, 1023-nulaY2, 0, 100);
  else
    y2 = -map(y2, -nulaY2, 0, -100, 0);


}

void setup()
{
   Keyboard.begin();
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(tlacitko, INPUT);
  pinMode(tlacitko2, INPUT);
  pinMode(tlacitko3, INPUT);
  pinMode(tlacitko4, INPUT);
  pinMode(tlacitko5, INPUT);
  pinMode(tlacitko6, INPUT);
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(VRX2, INPUT);
  pinMode(VRY2, INPUT);
       Serial.begin(9600);       
  nulaX = analogRead(VRX);
  nulaY = analogRead(VRY);
  nulaX2 = analogRead(VRX2);
  nulaY2 = analogRead(VRY2);

}

void loop()
{
  if ( Serial.available())
  {
    char ch = Serial.read();
    if (ch == 'a')
    {
      analogWrite(red_light_pin, 255);
      }
      else{
      analogWrite(red_light_pin, 0);
      }
  }
  readJoy();
  // read the state of the pushbutton value:
  buttonState = digitalRead(tlacitko);
  buttonState2= digitalRead(tlacitko2);
  buttonState3= digitalRead(tlacitko3);
  buttonState4= digitalRead(tlacitko4);
  buttonState5= digitalRead(tlacitko5);
  buttonState6= digitalRead(tlacitko6);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) 
  {
    Serial.println("rotace vlevo");
  }
  if (buttonState2== HIGH)
  {
    Serial.println("strelba");
    }
  if(buttonState3 == HIGH)
  {
    Serial.println("rotace vpravo");
  }
  if(buttonState4 == HIGH)
  {
    Serial.println("strelba2");
  }
  if(buttonState5 == HIGH)
  {
    Serial.println("rotace vpravo2");
  }
  if(buttonState6 == HIGH)
  {
    Serial.println("rotace vlevo2");
    }
  if(x>5 || y>5 || x<-5 || y<-5)
  {
  Serial.print("x:");
  Serial.print(x);
  Serial.print(" y:");
  Serial.println(y);
  
  }
  if(x2>5 || y2 >5 || x2 <-5 || y2<-5)
  {
  Serial.print("x2:");
  Serial.print(x2);
  Serial.print(" y2:");
  Serial.println(y2);
  if(x2>10)
  {
     Keyboard.write('W');
      delayMicroseconds(1); 
  }
  if(x2<-10)
  {
    Keyboard.write('S');
     delayMicroseconds(1); 
  }
  if(y>10)
  {
    Keyboard.write('D');
     delayMicroseconds(1); 
    }
      if(y<-10)
  {
    Keyboard.write('A');
     delayMicroseconds(1); 
    }
  if(x2>90){
  analogWrite(red_light_pin, 0);
  analogWrite(green_light_pin, 255);
  }
  if(x2<90 && x2 > 70){
    analogWrite(red_light_pin, 255);
  analogWrite(green_light_pin, 140);
    }
    if(x2<70 && x2> 50){
      analogWrite(red_light_pin, 255);
  analogWrite(green_light_pin, 0);
      }
  }
  if(x2<50)
  {
  analogWrite(red_light_pin, 0);
 
  analogWrite(green_light_pin, 0);
  }


  delay(100);               
}
