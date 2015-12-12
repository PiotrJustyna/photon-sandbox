// ---------------------------------------------------
// Reading photoresistor's resistance using a variable
// ---------------------------------------------------

int photoresistor = A0;
int power = A5;
int resistance = 0;

void setup()
{
  pinMode(photoresistor, INPUT);
  pinMode(power, OUTPUT);
  
  digitalWrite(power, HIGH);

  Spark.variable("resistance", &resistance, INT);
}

void loop()
{
  resistance = analogRead(photoresistor);
}
