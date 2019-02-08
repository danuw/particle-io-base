// version control

// v0.1: initial template

// Wiring: update below "schema" or simply list pins and plugging
/* 
         -----[    ]-----
        -|VIN        3V3|-    
        -|GND        RST|-
        -|TX        VBAT|-
        -|RX         GND|-
        -|WKP         D7|-
        -|DAC         D6|-
        -|A5          D5|- RELAY1
        -|A4          D4|-
        -|A3          D3|- 
        -|A2          D2|- 
        -|A1          D1|- 
        -|A0          D0|- LED
          \____________/
 
*/

String version = "<file-name> v0.1";



int lastPublish;
int publishPause = 5000; // in ms - delay before next publish

bool canPublish() {
  return millis() > (lastPublish + publishPause);
}

// Program
void setup() {

    lastPublish = millis();
    Particle.publish("started", version);
    // First, declare all of our pins. This lets our device know which ones will be used for outputting voltage, and which ones will read incoming voltage.

    Particle.variable("version", version);
}


// Next is the loop function...

void loop() {
    
    // TODO: update with you running logic here
    String command = "loop-CHANGEME";
    if(canPublish()){
        Particle.publish("command", "{ \"command\":\""+command +"\", \"version\":"+ version+", \"othervalue\":"+"0 }");
        lastPublish = millis();
    }
    
}
