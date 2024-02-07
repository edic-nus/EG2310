## Setting up the ESP32:
Download the Arduino IDE.

### Using the Arduino IDE:

Follow this tutorial 
https://randomnerdtutorials.com/installing-esp32-arduino-ide-2-0/

1. Open the IDE and copy the code from main.ino (located in src/ in this repository) into a new .ino file
2. Open the "Library Manager" tab and download the libraries: Arduino Uno Wifi Dev Ed Library, ArduinoJson
3. Select the board FireBeetle-ESP32 or ESP32 Wrover Kit (all versions)
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
