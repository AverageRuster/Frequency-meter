#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int Htime = 0;    
int Ltime = 0;   
int Ttime = 0;
int counter = 0;
float frequency;

bool currentInput = LOW;
bool lastInput = LOW;

void setup()
{
  pinMode(8,INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Frequency meter"); 

  if (counter < 10)
  {
    Htime += pulseIn(8,HIGH);
    Ltime += pulseIn(8,LOW);
    counter++;
    delay(50);
  }
  else
  {
    lcd.clear();    
    Ttime = (Htime + Ltime)/10;
    Serial.println(Ttime);
    frequency = 1000000/Ttime;
    lcd.setCursor(0,1);
    if (frequency < 1000)
    {
      lcd.print("F = ");
      lcd.print(frequency);
      lcd.print(" Hz");
    }
    else if (frequency >= 1000 && frequency < 1000000)
    {
      lcd.print("F = ");
      lcd.print(frequency/1000);
      lcd.print(" kHz");
      //lcd.print(frequency);
    }
    Htime = 0;
    Ltime = 0;
    counter = 0;
  } 
}
