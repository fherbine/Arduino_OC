const int leftTopLed = 2;
const int leftBottomLed = 3;
const int centerLed = 4;
const int rightTopLed = 6;
const int rightBottomled = 5;
const int button = 7;

void  setup(void)
{
  for (int led = 2; led < 7; led++)
    pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  randomSeed(analogRead(0));
  Serial.begin(9600);
  diceAlarm();
}

void  loop(void)
{
  int     n;
  boolean state = digitalRead(button);
  
  if (!state)
  {
    for (int i = 100; i < 250; i += 10)
    {
      n = random(6);
      Serial.println(n);
      allDisplays(n);
      delay(i);
    }
  }
}

void  allDisplays(int n)
{
  displayNone();
  switch (n)
  {
    case 0:
      displayNone();
      break;
    case 1:
      displayOne();
      break;
    case 2:
      displayTwo();
      break;
    case 3:
      displayThree();
      break;
    case 4:
      displayFour();
      break;
    case 5:
      displayFive();
      break;
    default:
      diceAlarm();
      break;
  }
}

void  diceAlarm(void)
{
  for (int i = 0; i < 2; i++)
  {
    displayNone();
    delay(250);
    displayFive();
    delay(250);
  }
  displayNone();
}

void  displayNone(void)
{
  for (int led = 0; led < 7; led++)
    digitalWrite(led, LOW);
}

void displayOne(void)
{
  digitalWrite(centerLed, HIGH);
}

void  displayTwo(void)
{
  digitalWrite(leftBottomLed, HIGH);
  digitalWrite(rightTopLed, HIGH);
}

void  displayThree(void)
{
  displayTwo();
  displayOne();
}

void  displayFour(void)
{
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
