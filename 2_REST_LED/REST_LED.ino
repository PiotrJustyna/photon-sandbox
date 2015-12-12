// ---------------------------------
// Controlling LED over the Internet
// ---------------------------------

int led = 7;

void setup()
{
  pinMode(led, OUTPUT);
  
  Spark.function("led", ledToggle);
  
  digitalWrite(led, LOW);
}

void loop() { }

int ledToggle(String command)
{
  int result = -1;

  if (command == "on")
  {
    digitalWrite(led, HIGH);

    result = 1;
  }
  else if (command == "off")
  {
    digitalWrite(led, LOW);
    
    result = 0;
  }
  
  return result;
}
