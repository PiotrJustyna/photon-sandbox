// -----------------------------------------
// Controlling the speaker over the Internet
// -----------------------------------------

int tonePin = D1;

void setup()
{
    Spark.function("sound", soundToggle);
}

void loop() { }

int soundToggle(String command)
{
    int result = -1;

    if (command == "on")
    {
        tone(tonePin, 440);

        result = 1;
    }
    else if (command == "off")
    {
        noTone(tonePin);

        result = 0;
    }

    return result;
}
