//#include <UbidotsESP8266.h>
#include "Ubidots.h"
#include <SoftwareSerial.h>

#define SSID "APTO_66_EXT"
#define PASS "99790035"

#define TOKEN "BBFF-e5WcenjrEl3lAeCbZqw3CmSvtbzhAt" //BBFF-af42a4a1b499962a0e79f23840e6959e3f5
#define ID "62ba72167a723207ffed834d" //"62ba71465d55ec071c34452b" "BBFF-TaMOScmg3kpkv4ODDuiFVkPWXv1h4V"

Ubidots client (TOKEN);

void setup() {
  Serial.begin(9600);
  client.wifiConnection(SSID, PASS);
}

void loop() {
  int value = 1;
  client.add(ID, value);
  client.sendAll();
}
