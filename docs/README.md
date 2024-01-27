# HTTP Docs

## Request

The format for making a [HTTP POST Request](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods/POST) will be the following:

```json
{
  "action": "openDoor",
  "parameters": {
    "robotId": "TurtleBot3_ID"
  }
}
```

## Response

When the request is successful, the following will be returned:

```json
{
  "status": "success",
  "data": {
    "doorOpened":  random(1, 3) == 1 ? "door1" : "door2"
  }
}
```

When the request is unsuccessful due to an error or anything else, the following will be returned:

```json
{
  "status": "error",
  "message": "Error description"
}
```
