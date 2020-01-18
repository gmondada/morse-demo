/*
 * Morse
 * Use the Arduino/ESP LED to output morse messages.
 */

#include <string>
#include "morse_code.h"

#define LED_ON  LOW
#define LED_OFF HIGH

#define DASH_TIME       400   // time to keep LED on for a dash
#define DOT_TIME        100   // time to keep LED on for a dot
#define OFF_TIME        200   // time between dashes and dots
#define CHAR_SEP_TIME   400   // time between characters
#define WORD_SEP_TIME   1000  // time between words

void dash() {
  digitalWrite(LED_BUILTIN, LED_ON);   // turn the LED on
  delay(DASH_TIME);                    // wait time for a dash
  digitalWrite(LED_BUILTIN, LED_OFF);  // turn the LED off
  delay(OFF_TIME);
}

void dot() {
  digitalWrite(LED_BUILTIN, LED_ON);   // turn the LED on
  delay(DOT_TIME);                     // wait time for a dot
  digitalWrite(LED_BUILTIN, LED_OFF);  // turn the LED off
  delay(OFF_TIME);
}

void outputMorseMessage(std::string s) {
  for (int i = 0; s[i]; i++) {
    if (i > 0)
      delay(CHAR_SEP_TIME);
    if (s[i] == ' ') {
      delay(WORD_SEP_TIME);
    } else {
      std::string code = morse::encode(s[i]);
      for (int j = 0; code[j]; j++) {
        if (code[j] == '-')
          dash();
        else
          dot();
      }
    }
  }
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  outputMorseMessage("Hello Makers");
  delay(WORD_SEP_TIME);
}
