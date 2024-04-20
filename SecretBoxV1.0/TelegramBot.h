/*
 * app_driver.h
 *
 *  Created on: Mar 21, 2024
 *      Author: Karim Emad
 */

#ifndef TELEGRAMBOT_H_
#define TELEGRAMBOT_H_

/**********Include Section*************/
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#define BOTtoken "6789606163:AAH_zVPd0x06JRnBW2TtV8cBu7DKu26fufI"   // Replace with your Telegram token
#define CHAT_ID "5335070779"                    // Replace with your telegram ID
const char* ssid = "Medo"; // Replace with your Wi-Fi SSID
const char* password = "medo4923"; // Replace with your Wi-Fi password

void bot_init(void);
#endif
