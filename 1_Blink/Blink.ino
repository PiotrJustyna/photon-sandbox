// -----
// Blink
// -----

// What's interesting, the sample code suggests using 'D7' instead of '7', which obviously works.
// I prefer to stick to digits only, though.
int led = 7;

void setup()
{
    pinMode(led, OUTPUT);
}

void loop()
{
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
}

