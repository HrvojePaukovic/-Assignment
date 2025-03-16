const int led1 = LED_BUILTIN;  // Built-in LED on Nano 33 BLE Sense Lite (Pin 13)
const int led2 = 2;  // External LED connected to Pin 2

unsigned long previousMillisLED1 = 0;
unsigned long previousMillisLED2 = 0;
const long intervalLED1 = 2000;  // 2 seconds
const long intervalLED2 = 5000;  // 5 seconds

void setup() {
    pinMode(led1, OUTPUT);  // Set built-in LED as output
    pinMode(led2, OUTPUT);  // Set external LED as output
    Serial.begin(115200);   // Start Serial Monitor
}

void loop() {
    unsigned long currentMillis = millis();

    // Toggle LED1 (built-in LED) every 2 seconds
    if (currentMillis - previousMillisLED1 >= intervalLED1) {
        previousMillisLED1 = currentMillis;
        digitalWrite(led1, !digitalRead(led1));  // Toggle LED1
        Serial.println("LED1 (Built-in) Toggled");
    }

    // Toggle LED2 (external LED) every 5 seconds
    if (currentMillis - previousMillisLED2 >= intervalLED2) {
        previousMillisLED2 = currentMillis;
        digitalWrite(led2, !digitalRead(led2));  // Toggle LED2
        Serial.println("LED2 (External) Toggled");
    }
}
