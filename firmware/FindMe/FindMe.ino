#include "Arduino.h"
#include <EMailSender.h>
#include <ESP8266WiFi.h>
#include "secrets.h"   // copy secrets.example.h to secrets.h and fill it in

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;

uint8_t connection_state = 0;
uint16_t reconnect_interval = 10000;

EMailSender emailSend(EMAIL_SENDER, EMAIL_APP_PASSWORD);
EMailSender emailSend1(EMAIL_SENDER, EMAIL_APP_PASSWORD);

uint8_t WiFiConnect(const char* nSSID = nullptr, const char* nPassword = nullptr)
{
    static uint16_t attempt = 0;
    Serial.print("Connecting to ");
    if(nSSID) {
        WiFi.begin(nSSID, nPassword);
        Serial.println(nSSID);
    }

    uint8_t i = 0;
    while(WiFi.status()!= WL_CONNECTED && i++ < 50)
    {
        delay(200);
        Serial.print(".");
    }
    ++attempt;
    Serial.println("");
    if(i == 51) {
        Serial.print("Connection: TIMEOUT on attempt: ");
        Serial.println(attempt);
        if(attempt % 2 == 0)
            Serial.println("Check if access point available or SSID and Password\r\n");
        return false;
    }
    Serial.println("Connection: ESTABLISHED");
    Serial.print("Got IP address: ");
    Serial.println(WiFi.localIP());
    return true;
}

void Awaits()
{
    uint32_t ts = millis();
    while(!connection_state)
    {
        delay(50);
        if(millis() > (ts + reconnect_interval) && !connection_state){
            connection_state = WiFiConnect();
            ts = millis();
        }
    }
}

void setup()
{
    Serial.begin(115200);

    connection_state = WiFiConnect(ssid, password);
    if(!connection_state)  // if not connected to WIFI
        Awaits();          // constantly trying to connect

    EMailSender::EMailMessage message;
    message.subject = ALERT_SUBJECT;
    message.message = String(ALERT_TEXT) + LOCATION_URL;

    EMailSender::Response resp = emailSend.send(EMAIL_RECIPIENT_1, message);
    EMailSender::Response resp1 = emailSend1.send(EMAIL_RECIPIENT_2, message);
    Serial.println("Sending status: ");
    Serial.println(resp.status);
    Serial.println(resp.code);
    Serial.println(resp.desc);
    Serial.println(resp1.status);
    Serial.println(resp1.code);
    Serial.println(resp1.desc);
}

void loop()
{

}
