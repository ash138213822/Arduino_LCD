#include <LiquidCrystal.h>
 LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  pinMode(8, INPUT_PULLUP);
   pinMode(7, INPUT_PULLUP);
   pinMode(13, INPUT_PULLUP);
   
  
  
  lcd.begin(16, 2);
}

void loop() {
  int h, m, s;
  char flge;
  double k1, k2, k3, k;
  double t;
  t = analogRead(A0);
  t = t * 100/1024;
  for(h=0;h<24;h++)
  {
  for(m=0;m<60;m++)
  {
  for(s=0;s<60;s++)
  {
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(9, 0);
    
    t = analogRead(A0);
    flge = digitalRead(13);
    if(flge)
    { 
    t = t * 100/1024;
    if(t<=33)
    {
      k = t*255/33;
      analogWrite(9, k);
    }
    else if(t<=66 && t>33)
    {
       k = (t-33)*255/33;
       analogWrite(9, 255);
       analogWrite(6, k);
       
      
    
    }
    else
    {
      k = (t-66)*255/66;
       analogWrite(9, 255);
       analogWrite(6, 255);
       analogWrite(10, k);
    }
    }
    
    else
    { 
    t = (1.8*t * 100/1024) +32;
    if(t<=91.4)
    {
      k = t*255/91.4;
      analogWrite(9, k);
    }
    else if(t<=151.8 && t>91.4)
    {
       k = (t-91.4)*255/91.4;
       analogWrite(9, 255);
       analogWrite(6, k);
       
      
    
    }
    else
    {
      k = (t-151.8)*255/151.8;
       analogWrite(9, 255);
       analogWrite(6, 255);
       analogWrite(10, k);
    }
    }
    k1 = digitalRead(8);
    k2 = digitalRead(7);
     if(k1==0) 
     {
      if(h<23)h++;
      
      else
      {
        h=0;
      }
      
      
     }
     if(k2==0)
     {
     if(m<59)m++;
      
      else
      {
        m=0;
      }
     
     }
      lcd.setCursor(0, 0);
  lcd.print("time: ");
  lcd.print(h);
  lcd.print(":");
  lcd.print(m);
  lcd.print(":");
  lcd.print(s);
  if(h<12) lcd.print("AM "); 
  else lcd.print("PM ");
  
  delay(1000);
   lcd.setCursor(0, 1);
   lcd.print("temp:");
   lcd.print(t);
   if(flge) lcd.print(" C ");
    else  lcd.print(" F ");
  
  }
  }
  }
  h=m=s=0;
  
  
} 
