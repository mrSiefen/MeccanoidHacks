#include <Meccanoid.h>

/* typedefs for convenience */
typedef MeccanoLed   Led;

/* Note that their needs to be a 22k ohm pull-up resistor on chain input,
      See https://www.mrsiefensrobotemporium.com/downloads/Meccano_SmartModuleProtocols_2015.pdf Smart Module Protocol
      (bottom of PDF) for more details. */

/* PWM pin for LED */
int pin = 2;

/* Red, Green, Blue and userInput Variables */
byte red = 0;
byte green = 0;
byte blue = 0;
String userInput = "";

/* define chain and PWM pin for it */
Chain chain(pin);

/* define modules to use and their positions */
Led eyes = chain.getLed(0);   // only thing on chain  (0)

void setup() {
  // startup serial
  Serial.begin(9600);
}

void loop() {
  // update chain to poll for input
  chain.update();

  if (eyes.justConnected()) {
    Serial.println("Led connected! Turning OFF");
    eyes.setColor(0, 0, 0, 0);
  }

  if (eyes.isConnected()) {
    // Get the users input
    Serial.print("Enter Red Value: ");
    while (Serial.available()==0) {  }
    red = Serial.parseInt();
    Serial.println(red);
    Serial.print("Enter Green Value: ");
    while (Serial.available()==0) {  }
    green = Serial.parseInt();
    Serial.println(green);
    Serial.print("Enter Blue Value: ");
    while (Serial.available()==0) {  }
    blue = Serial.parseInt();
    Serial.println(blue);
    eyes.setColor(red, green, blue, 0);
    Serial.println("Setting Colors: " + String(red) + ", " + String(green) + ", " + String(blue));
    Serial.println("");
  }
}
