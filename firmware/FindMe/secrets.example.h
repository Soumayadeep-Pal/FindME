// Copy this file to "secrets.h" (same folder) and fill in your own values.
// secrets.h is git-ignored, so your credentials are never committed.
#pragma once

// Wi-Fi network the device connects to
#define WIFI_SSID          "your-wifi-name"
#define WIFI_PASSWORD      "your-wifi-password"

// Sender Gmail account. Use a Google "App password" (not your normal password):
// https://myaccount.google.com/apppasswords
#define EMAIL_SENDER       "sender@gmail.com"
#define EMAIL_APP_PASSWORD "xxxx xxxx xxxx xxxx"

// Who receives the alert
#define EMAIL_RECIPIENT_1  "recipient1@example.com"
#define EMAIL_RECIPIENT_2  "recipient2@example.com"

// Message content
#define ALERT_SUBJECT      "FindMe_Security_Alert"
#define ALERT_TEXT         "Danger! Help is needed. Location tracking successful. Location link: "
#define LOCATION_URL       "https://your-location-page.example.com/"
