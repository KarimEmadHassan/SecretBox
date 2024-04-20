
#include "app.h"
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include "TelegramBot.h"
#define Buzzer 4
// ================================================================
// ===                    GLOBAL VARIABLES                     ===
// ================================================================
float distance;
bool open_Counter = 1;
bool fall_Counter = 1;
float Yaw;
float Pitch;
float Roll;
//LCD_INIT
const int rs = 25, en = 26, d4 = 13, d5 = 12, d6 = 14, d7 = 27;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void app_init()
{
  //Buzzer init
  pinMode(Buzzer, OUTPUT);
  //MPU6050 init
  mpu_init();
  //UltraSonic init
  UltraSonic_init();
  //LCD init  
  lcd.begin(16, 2);
  lcd.clear();
  //LCD_init();
  bot_init();
}


// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void app_Start()
{
  checkBox_isOpened();
  checkBox_hasFalled();
  //checkBox_isOpened_AND_Falled();
}

char checkBox_isOpened()
{
distance = Ultrasonic_get_distance();
if ( distance < 19 ){
    digitalWrite(Buzzer, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Box is Safe!!");
     //lcd.setCursor(0, 1); 
     //lcd.print("                ");
    return 0;
    open_Counter = 1;
  }
  
  else {
    //Send alarm
    digitalWrite(Buzzer, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Box is Opened!!");
    // lcd.setCursor(0, 1); 
    // lcd.print("                ");
    //lcd.print(distance);
    return 1;

   while ( open_Counter == 1 ){
      open_Counter = 0;
      //bot.sendMessage(CHAT_ID, "Box is open!", "");
    }
  }
}

char checkBox_hasFalled(){
   mpu_Update();
    //Serial.print("Yaw:\t");
  Yaw   =  mpu_get_Yaw();
    //Serial.print("  Pitch:\t");
  Pitch =  mpu_get_Pitch();
    //Serial.print("  Roll:\t");
  Roll  =  mpu_get_Roll();

  if( (Pitch > 25) || (Pitch < -25) || (Roll > 25) || (Roll < -25))
  {
    lcd.setCursor(0, 1);
    lcd.print("Box has Fallen!!");
    while ( fall_Counter == 1){
      fall_Counter = 0;
      //bot.sendMessage(CHAT_ID, "Box has Fallen!", "");
    }
     //lcd.setCursor(0, 0); 
     //lcd.print("                ");
    return 1;
  }
  else{
    fall_Counter = 1;
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }

  return 0;
}
