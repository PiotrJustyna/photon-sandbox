To use, GET the following from your Photon:

URL | Form Data
--- | ---
[URL](https://api.particle.io/v1/devices/your-device-ID-goes-here/resistance?access_token=your-access-token-goes-here) | -

Wiring:

* photoresistor: connect pins ```A0``` and ```A5```
* 220Ohm resistor: connect pins ```A0``` and ```GND``` 

Sample Response:

```json
{
  "cmd": "VarReturn",
  "name": "resistance",
  "result": 698,
  "coreInfo": {
    "last_app": "",
    "last_heard": "2015-12-12T14:42:40.898Z",
    "connected": true,
    "last_handshake_at": "2015-12-12T14:40:55.030Z",
    "deviceID": "your-device-ID",
    "product_id": 6
  }
}
```
