// ----------------------------------------------------
// Communicating with the host PC over the serial port.
// ----------------------------------------------------

void setup() {
  Serial.begin(57600);

  while (!Serial) { }
}

void loop()
{
  Serial.println("What am I doing with my life?");
  delay(3000);
}
