# FindMe – A Tracking Device for Women Safety

FindMe is a wearable safety prototype (built into a shoe) that helps locate a person who is in danger. When triggered, the device connects to Wi-Fi and e-mails a location link to trusted contacts, so help can reach her quickly.

B.Tech project, 5th semester, Electronics & Instrumentation Engineering, Narula Institute of Technology (MAKAUT), 2023.

## Team
- Avrajeet Ghosh
- Ankita Show
- Soumayadeep Pal
- Guides: Dr. Bikas Mondal and Dr. Sangamitra Layak, Narula Institute of Technology

## How it works
1. The toggle switch powers the NodeMCU (ESP8266) from a Li-Po battery.
2. The NEO-6M GPS module provides latitude and longitude.
3. The position is sent to a web page that shows the current place on a map (Google Maps APIs: geocoding, geolocation, maps JavaScript, places, directions).
4. The firmware connects to Wi-Fi and sends an alert e-mail with the location link to the configured recipients (e.g. family and the nearest police station).

> **Note:** the firmware in `firmware/FindMe` implements steps 1 and 4 (Wi-Fi connection and the e-mail alert). The GPS reading and map web page described above are part of the project design and presentation but are not included in this sketch.

## Hardware
| Part | Purpose |
|------|---------|
| NodeMCU ESP8266 | Microcontroller with Wi-Fi |
| u-blox NEO-6M GPS module + antenna | Location |
| Li-Po battery + charging point | Power |
| Toggle switch | Turn the device on/off |

Wiring: see [`docs/connection-diagram.png`](docs/connection-diagram.png).

## Software
Arduino IDE (ESP8266 board package) with the **EMailSender** library (install from the Library Manager).

## Setup
1. Clone this repository and open `firmware/FindMe/FindMe.ino` in the Arduino IDE.
2. Copy `firmware/FindMe/secrets.example.h` to `firmware/FindMe/secrets.h` and fill in your Wi-Fi details, a Gmail **app password**, the recipients and your location page URL.
3. Select your NodeMCU board and port, then upload.

`secrets.h` is git-ignored, so your credentials stay on your computer.

## Repository layout
```
FindMe/
├── firmware/FindMe/
│   ├── FindMe.ino
│   └── secrets.example.h
├── docs/
│   ├── FindMe_Presentation.pdf
│   └── connection-diagram.png
├── LICENSE
└── README.md
```

## Future scope
Fall detection, solar charging, a panic button, and an audio/camera module to capture evidence.

## License
MIT – see [LICENSE](LICENSE).
