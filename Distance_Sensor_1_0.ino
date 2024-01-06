#include <LiquidCrystal_I2C.h>
#include <Wire.h>
const int Piezo = 11;
const int trig = 12;
const int echo = 13;
int LEDS[] = {7,6,5,4,3};

int duration = 0;
int distance = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup(){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  for (int i = 0; i < 5; i++){
    pinMode(LEDS[i], OUTPUT);
  }
  lcd.init();
  lcd.backlight();
}

void loop(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 28.5;
  if (distance <= 20){
    tone(Piezo, 1000);
    for (int i = 0; i < 5; i++){
      if (i == 0){
        digitalWrite(LEDS[i], HIGH);
      }
      else{
        digitalWrite(LEDS[i], LOW);
      }
    }
    lcd.setCursor(0, 0);
    lcd.println("Distance: ");

    lcd.setCursor(0, 1);
    lcd.println(distance);
  }
  else if(distance > 20 && distance <= 40){
    tone(Piezo, 800);
    for (int i = 0; i < 5; i++){
      if (i == 1){
        digitalWrite(LEDS[i], HIGH);
      }
      else{
        digitalWrite(LEDS[i], LOW);
      }
    }
    lcd.setCursor(0, 0);
    lcd.println("Distance: ");

    lcd.setCursor(0, 1);
    lcd.println(distance);
  }
  else if (distance > 40 && distance <= 60){
    lcd.clear();
    tone(Piezo, 600);
    for (int i = 0; i < 5; i++){
      if (i == 2){
        digitalWrite(LEDS[i], HIGH);
      }
      else{
        digitalWrite(LEDS[i], LOW);
      }
    }
    lcd.setCursor(0, 0);
    lcd.println("Distance: ");

    lcd.setCursor(0, 1);
    lcd.println(distance);
  }
  else if (distance > 60 && distance <= 80){
    lcd.clear();
    tone(Piezo, 400);
    for (int i = 0; i < 5; i++){
      if (i == 3){
        digitalWrite(LEDS[i], HIGH);
      }
      else{
        digitalWrite(LEDS[i], LOW);
      }
    }
    lcd.setCursor(0, 0);
    lcd.println("Distance: ");

    lcd.setCursor(0, 1);
    lcd.println(distance);
  }
  else if (distance > 80 && distance <= 100){
    tone(Piezo, 200);
    for (int i = 0; i < 5; i++){
      if (i == 4){
        digitalWrite(LEDS[i], HIGH);
      }
      else{
        digitalWrite(LEDS[i], LOW);
      }
    }
    lcd.setCursor(0, 0);
    lcd.println("Distance: ");

    lcd.setCursor(0, 1);
    lcd.println(distance);
  }
  else{
    noTone(Piezo);
    for (int i = 0; i < 5; i++){
      digitalWrite(LEDS[i], LOW);
    }
    lcd.setCursor(0, 0);
    lcd.println("Distance: ");

    lcd.setCursor(0, 1);
    lcd.println(distance);
  }
  delay(300);
}
