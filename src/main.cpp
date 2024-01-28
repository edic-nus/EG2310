#include <Arduino.h>

#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>

using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

// change ssid and password
const char* ssid = "username";
const char* password = "password";

// Create a web server on port 80
WebServer server(80);

void setup() {
  Serial.begin(115200);

  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

    // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();

  Serial.println("Connected to WiFi");

  // Define endpoint and corresponding handler function
  server.on("/openDoor", HTTP_POST, handleOpenDoor);

  // Start the server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  // Handle client requests
  server.handleClient();
}

void handleOpenDoor() {
  if (server.hasArg("plain") == false) {
    // If the request does not have a body
    server.send(400, "application/json", "{\"status\":\"error\",\"message\":\"Bad Request - No Data Received\"}");
    return;
  }

  // Parse JSON object from request
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, server.arg("plain"));
  String action = doc["action"];
  String robotId = doc["parameters"]["robotId"];

  // Check the action value
  if (action == "openDoor") {
    // Randomly decide which door to open
    String doorToOpen = random(1, 3) == 1 ? "door1" : "door2";

    // Send response back to TurtleBot3
    String response = "{\"status\":\"success\",\"data\":{\"doorOpened\":\"" + doorToOpen + "\"}}";
    server.send(200, "application/json", response);

    Serial.println("Command received to open " + doorToOpen);
  } else {
    server.send(400, "application/json", "{\"status\":\"error\",\"message\":\"Invalid Action\"}");
  }
}