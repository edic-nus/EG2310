# HTTP Docs

## List of Status Codes Used

- 200 - Success
- 400 - Bad Request
- 500 - Internal Server Error

## Request

The format for making a [HTTP POST Request](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods/POST) will be the following:

```json
POST http://<ESP_IP_ADDRESS>/openDoor
Content-Type: application/json

{
  "action": "openDoor",
  "parameters": {
    "robotId": "TurtleBot3_ID"
  }
}
```

### Notes

- Replace <ESP_IP_ADDRESS> with the actual IP address or hostname of the ESP32 web server.
- Ensure that the robotId is set correctly on the TurtleBot.

## Response

When the request is successful, the following will be returned:

```json
HTTP/1.1 200 OK
Content-Type: application/json

{
  "status": "success",
  "data": {
    "message": "door1" // OR "door2" depending on random number generator
  }
}
```

When the request is unsuccessful due to an error, the following will be returned:

```json
HTTP/1.1 400 Bad Request
Content-Type: application/json

{
  "status": "error",
  "data": {
    "message": "Error description"
  }
}
```

### Notes

- Check the HTTP status code to determine the success or failure of the request.
- If an error occurs, review the error message for troubleshooting and consider retrying the request.
