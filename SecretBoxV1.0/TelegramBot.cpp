#include "TelegramBot.h"

void bot_init(void){
  
  WiFiClientSecure client;
  UniversalTelegramBot bot(BOTtoken, client);

  client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  configTime(0, 0, "pool.ntp.org");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  bot.sendMessage(CHAT_ID, "Wifi Connected!", "");
  bot.sendMessage(CHAT_ID, "System has Started!!", "");
}
