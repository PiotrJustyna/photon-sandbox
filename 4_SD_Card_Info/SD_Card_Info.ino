// ----------------------
// Reading SD card's info
// ----------------------

#include "sd-card-library-photon-compat/sd-card-library-photon-compat.h"

const uint8_t chipSelect = A2;

Sd2Card card;
SdVolume volume;

int statusLed = D7;
int cardTypeSD1 = -1;
int cardTypeSD2 = -1;
int cardTypeSDHC = -1;
int volumeFAT = -1;
int volumeSize = -1;

void setup()
{
  pinMode(statusLed, OUTPUT);
  
  Spark.variable("cardTypeSD1", &cardTypeSD1, INT);
  Spark.variable("cardTypeSD2", &cardTypeSD2, INT);
  Spark.variable("cardTypeSDHC", &cardTypeSDHC, INT);
  Spark.variable("volumeFAT", &volumeFAT, INT);
  Spark.variable("volumeSize", &volumeSize, INT);
  
  Spark.function("readCardInfo", readCardInfo);
  
  digitalWrite(statusLed, LOW);
}

void loop() { }

int readCardInfo(String command)
{
  int result = -1;

  digitalWrite(statusLed, HIGH);

  if (card.init(SPI_HALF_SPEED, chipSelect))
  {
    switch(card.type())
    {
      case      SD_CARD_TYPE_SD1:
                cardTypeSD1 = 1;
                break;

      case      SD_CARD_TYPE_SD2:
                cardTypeSD2 = 1;
                break;

      case      SD_CARD_TYPE_SDHC:
                cardTypeSDHC = 1;
                break;

      default:  return result;
    }
    
    if (volume.init(card))
    {
      volumeFAT = volume.fatType();
      
      uint32_t tempVolumeSize = volume.blocksPerCluster();
      tempVolumeSize *= volume.clusterCount();
      tempVolumeSize *= 512;  // B
      tempVolumeSize /= 1024; // KB
      tempVolumeSize /= 1024; // MB
      
      volumeSize = tempVolumeSize;

      result = 1;
    }
  }

  digitalWrite(statusLed, LOW);
  
  return result;
}
