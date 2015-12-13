![SD Card](https://raw.githubusercontent.com/PiotrJustyna/photon-sandbox/master/4_SD_Card_Info/IMG_20151213_202048.jpg)

For this project I'm using [SparkFun microSD transflash brakout board](https://www.sparkfun.com/products/544).

Wiring:

microSD brakout board | Photon
--- | ---
D0 | A4
GND | GND
SCK | A3
VCC | 3V3
D1 | A5
CS | A2

To use, POST the following to your Photon to prepare the SD card details:

URL | Form Data
--- | ---
[URL](https://api.particle.io/v1/devices/your-device-ID-goes-here/readCardInfo?access_token=your-access-token-goes-here) | -

If the ```result``` is ```1```, SD card properties can be read one by one. To list available card properties, GET the following from your Photon:

URL | Form Data
--- | ---
[URL](https://api.particle.io/v1/devices/your-device-ID-goes-here/?access_token=your-access-token-goes-here) | -

Expected result:

```json
{
  "id": "your-device-ID",
  "name": "Photon 1",
  "connected": true,
  "variables": {
    "cardTypeSD1": "int32",
    "cardTypeSD2": "int32",
    "cardTypeSDHC": "int32",
    "volumeFAT": "int32",
    "volumeSize": "int32"
  },
  "functions": [
    "readCardInfo"
  ],
  "cc3000_patch_version": "wl0: Nov  7 2014 16:03:45 version 5.90.230.12 FWID 01-1a002c7c",
  "product_id": 6,
  "last_heard": "2015-12-13T20:29:46.705Z"
}
```

To get values of selected properties GET the following from your Photon:

URL | Form Data
--- | ---
[volumeSize URL](https://api.particle.io/v1/devices/your-device-ID-goes-here/volumeSize?access_token=your-access-token-goes-here) | -

