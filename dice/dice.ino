const int leftTopLed = 2;
const int leftBottomLed = 3;
const int centerLed = 4;
const int rightTopLed = 6;
const int rightBottomled = 5;
const int button = 7;

void  setup(void)
{
  for (int led = 2; led < 7; led++) // On definit les leds comme des Sorties
    pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP); // Le bouton est une entree se servant de la resistance pullUp integree dans l'Arduino (20kOhms)
  randomSeed(analogRead(0));
  diceAlarm(); // cette fonction signale a l'utilisateur la fin du setup en faisant clignoter toutes les LEDs deux fois
}

void  loop(void)
{
  int     n;
  boolean state = digitalRead(button); // On lit l'etat du bouton
  
  if (!state) // si le bouton -> 0V on valide la condition et on entre
  {
    for (int i = 100; i < 250; i += 10) // on ralenti la frequence de 10 ms a chaque boucles soit de 100ms a 250, 15 passages dans cette boucle
    {
      n = random(6); // on tire un nombre entre 0  et 5
      allDisplays(n);
      delay(i);
    }
  }
}

void  allDisplays(int n)
{
  displayNone();
  switch (n) // ici on appel la bonne fonction a l'aide d'un switch(), qui equivaut a une foret de if()
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
      diceAlarm(); // si le chiffre est in coherent => erreur cotes programmeur on fait clignoter toutes les LEDs pour signaler le probleme
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
