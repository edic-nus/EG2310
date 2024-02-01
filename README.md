# EG2310
You pass the mod if the bot moves past the start line, its that simple.

## Setting up the ESP32:
You have 2 options - Using the Arduino IDE or using PlatformIO.

### Using PlatformIO:
1. Clone this repository
2. On PlatformIO>>{board_name}>>General, select "Upload and Monitor"

### Using the Arduino IDE:
1. Open the IDE and copy the code from main.cpp (located in src/ in this repository) into a new .ino file
2. Open the "Libary Manager" tab and download the libraries: Arduino Uno Wifi Dev Ed Library, ArduinoJson
3. Click onto the right arrow to upload the code onto the ESP32
4. Open up the serial monitor and change baudrate to 115200
## Testing the ESP32 web server
1. Connect your ESP32 to the computer and upload the code onto the board
2. Note down the IP address printed to the console. This will be the <ESP_IP_ADDRESS> used in the next step
3. Enter the following command in your computer's terminal:

```
curl -X POST http://<ESP_IP_ADDRESS>/openDoor -H "Content-Type: application/json" -d '{"action": "openDoor", "parameters": {"robotId": "<TurtleBot3_ID>"}}'
```

Note: replace <ESP_IP_ADDRESS> with the ESP32's IP address and <TurtleBot3_ID> with the ID of your Turtlebot
