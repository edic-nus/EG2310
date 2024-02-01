#include <Arduino.h>

#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

std::map<std::string, std::string> readCredentials(const std::string& filename) {
    std::map<std::string, std::string> credentials;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, '=')) {
            std::string value;
            if (std::getline(is_line, value)) {
                credentials[key] = value;
            }
        }
    }

    return credentials;
}

auto credentials = readCredentials("../.user");

// change ssid and password
String ssid = String(credentials["SSID"].c_str());
String password = String(credentials["PASSWORD"].c_str());

// Create a web server on port 80
WebServer server(80);

// Assign output variables to GPIO pins
const int output16 = 16;
const int output17 = 17;

void handleOpenDoor(String doorToOpen) {
  if (doorToOpen == "door1") {
    digitalWrite(output16, HIGH);
  } else {
    digitalWrite(output17, HIGH);
  }
}

void handleRequest() {
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

    // open the door
    handleOpenDoor(doorToOpen);

    // Send response back to TurtleBot3
    String response = "{\"status\":\"success\",\"data\":{\"message\":\"" + doorToOpen + "\"}}";
    server.send(200, "application/json", response);

    Serial.println("Command received to open " + doorToOpen);
  } else {
    server.send(400, "application/json", "{\"status\":\"error\",\"data\":{\"message\":\"Invalid Action\"}}");
  }
}

void setup() {
  Serial.begin(115200);

  // Initialize the output variables as outputs
  pinMode(output16, OUTPUT);
  pinMode(output17, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output16, LOW);
  digitalWrite(output17, LOW);

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
  server.on("/openDoor", HTTP_POST, handleRequest);

  // Start the server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  // Handle client requests
  server.handleClient();
}