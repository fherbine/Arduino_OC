const int leftTopLed = 2;
const int leftBottomLed = 3;
const int centerLed = 4;
const int rightTopLed = 6;
const int rightBottomled = 5;

void  setup(void)
{
  for (int led = 2; led < 7; led++)
    pinMode(led, OUTPUT);
    displayFive();
}

void  loop(void)
{
}

void  displayNone(void)
{
  for (int led = 0; led < 7; led++)
    digitalWrite(led, LOW);
}

void displayOne(void)
{
  displayNone();
  digitalWrite(centerLed, HIGH);
}

void  displayTwo(void)
{
  displayNone();
  digitalWrite(leftBottomLed, HIGH);
  digitalWrite(rightTopLed, HIGH);
}

void  displayThree(void)
{
  displayTwo();
  digitalWrite(centerLed, HIGH);
}

void  displayFour(void)
{
  displayNone();
  digitalWrite(leftTopLed, HIGH);
  digitalWrite(leftBottomLed, HIGH);
  digitalWrite(rightTopLed, HIGH);
  digitalWrite(rightBottomled, HIGH);  
}

void  displayFive(void)
{
  for (int led = 2; led < 7; led++)
    digitalWrite(led, HIGH);
}
