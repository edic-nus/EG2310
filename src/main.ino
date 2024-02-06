#include <WiFi.h>
#include <WebServer.h>
#include "ArduinoJson.h"

// Replace with your network credentials
const char* ssid = "";
const char* password = "";

// Create a web server on port 80
WebServer server(80);

// timeout variable
int successfulRequestCount = 0;

// Assign output variables to GPIO pins
const int output16 = 16;
const int output17 = 17;

void handleOpenDoor(String doorToOpen) {
  if (doorToOpen == "door1") {
    digitalWrite(output16, HIGH);
    digitalWrite(output17, LOW);
  } else {
    digitalWrite(output16, LOW);
    digitalWrite(output17, HIGH);
  }
}

void handleRequest() {
  if (server.hasArg("plain") == false) {
    // If the request does not have a body
    server.send(400, "application/json", "{\n\t\"status\":\"error\",\n\t\"message\":\"Bad Request - No Data Received\"\n}\n");
    return;
  }

  // Parse JSON object from request
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, server.arg("plain"));
  String action = doc["action"];
  String robotId = doc["parameters"]["robotId"];

  // Check the action value
  if (action == "openDoor") {
    
    // Reject request if too many http requests are sent at once
    if (successfulRequestCount >= 2) {
      server.send(400, "application/json", "{\n\t\"status\":\"error\",\n\t\"message\":\"Too many requests, try again later\"\n}\n");
      delay(20000);   // delay for 20 seconds
      successfulRequestCount = 0;
      return;
    }

    successfulRequestCount += 1;

    // Randomly decide which door to open
    String doorToOpen = random(1, 3) == 1 ? "door1" : "door2";

    // open the door
    handleOpenDoor(doorToOpen);

    // Send response back to TurtleBot3
    String response = "{\n\t\"status\":\"success\",\n\t\"data\":{\n\t\t\"message\":\"" + doorToOpen + "\"\n\t}\n}\n";
    server.send(200, "application/json", response);

    Serial.println("Command received to open " + doorToOpen);
  } else {
    server.send(400, "application/json", "{\n\t\"status\":\"error\",\n\t\"data\":{\n\t\t\"message\":\"Invalid Action\"\n\t}\n}\n");
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