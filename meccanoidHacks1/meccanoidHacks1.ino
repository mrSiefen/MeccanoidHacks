#include <Meccanoid.h>

/* typedefs for convenience */
typedef MeccanoLed   Led;
                        
/* Note that their needs to be a 22k ohm pull-up resistor on chain input,
    * See https://www.mrsiefensrobotemporium.com/downloads/Meccano_SmartModuleProtocols_2015.pdf Smart Module Protocol 
    * (bottom of PDF) for more details. */
    
/* PWM pin for LED */
int pin = 2;

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
            eyes.setColor(8, 0, 0, 0);
        }
    }
}
