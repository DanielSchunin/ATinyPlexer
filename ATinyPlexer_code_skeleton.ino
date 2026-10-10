#include "DigiKeyboard.h"

// Define the 15 dummy functions for each combination
void function1() { DigiKeyboard.println("Func 1"); }
void function2() { DigiKeyboard.println("Func 2"); }
void function3() { DigiKeyboard.println("Func 3"); }
void function4() { DigiKeyboard.println("Func 4"); }
void function5() { DigiKeyboard.println("Func 5"); }
void function6() { DigiKeyboard.println("Func 6"); }
void function7() { DigiKeyboard.println("Func 7"); }
void function8() { DigiKeyboard.println("Func 8"); }
void function9() { DigiKeyboard.println("Func 9"); }
void function10() { DigiKeyboard.println("Func 10"); }
void function11() { DigiKeyboard.println("Func 11"); }
void function12() { DigiKeyboard.println("Func 12"); }
void function13() { DigiKeyboard.println("Func 13"); }
void function14() { DigiKeyboard.println("Func 14"); }
void function15() { DigiKeyboard.println("Func 15"); }

// Read the current state of the 4 buttons and return a 4-bit value (0-15)
uint8_t readButtons() {
  uint8_t state = 0;
  // Based on the original code logic for reading pins
  if (digitalRead(0) == LOW) state |= (1 << 0);
  if (digitalRead(1) == LOW) state |= (1 << 1);
  if (digitalRead(2) == LOW) state |= (1 << 2);
  if (analogRead(A0) < 930)  state |= (1 << 3);
  return state;
}

void executeFunction(uint8_t combination) {
  switch (combination) {
    case 1: function1(); break;
    case 2: function2(); break;
    case 3: function3(); break;
    case 4: function4(); break;
    case 5: function5(); break;
    case 6: function6(); break;
    case 7: function7(); break;
    case 8: function8(); break;
    case 9: function9(); break;
    case 10: function10(); break;
    case 11: function11(); break;
    case 12: function12(); break;
    case 13: function13(); break;
    case 14: function14(); break;
    case 15: function15(); break;
  }
}

uint8_t lastStableState = 0;
uint8_t lastDebounceState = 0;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // 50ms debounce time to ensure stable combination

void setup() {
  // Setup pins according to original code
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT);
  pinMode(2, INPUT_PULLUP);
  // A0 is used as analog input, no pinMode needed
}

void loop() {
  // Good practice to call update for DigiKeyboard
  DigiKeyboard.update();

  uint8_t currentState = readButtons();

  // If the state changed, reset the debounce timer
  if (currentState != lastDebounceState) {
    lastDebounceTime = millis();
    lastDebounceState = currentState;
  }

  // If the state has been stable for longer than the debounce delay
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the stable state has changed since last time we triggered
    if (currentState != lastStableState) {
      lastStableState = currentState;
      if (lastStableState != 0) {
        executeFunction(lastStableState);
      }
    }
  }
}