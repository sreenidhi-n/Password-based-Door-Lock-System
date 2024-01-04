#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

/*  Define the rows and columns of the keypad and configure using the Keypad() function. */
const byte ROWS = 4;
const byte COLS = 3;
char keypad_keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {8, 7, 6, 5};
byte colPins[COLS] = {4, 3, 2};
Keypad myKeypad = Keypad(makeKeymap(keypad_keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;
const int buzzerPin = 10;
char password[5] = "2356"; // "2356/0"

char key; // for pressed key
char pass[5]; // for entered password
int position = 0; // position variable for keys to be displayed on the LCD display
int incorrectAttempts = 0;

/* setup function used to initialize components and values */
void setup() {
  lcd.init();
  lcd.backlight();
  myServo.attach(9);
  pinMode(buzzerPin, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  for (int i = 0; i < sizeof(pass); i++) {  // Clear buffer.
    pass[i] = '\0';
  }
}

void loop() {
  key = myKeypad.getKey();
  if (key != NO_KEY) {
    lcd.setCursor(position, 1);
    lcd.print("*");
    pass[position] = key;
    position++;
    if (position == 4) {
      position = 0;
      
      // Validate the password
      if (strcmp(pass, password) == 0) {  // Successful
        myServo.write(270);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Welcome!");
        tone(buzzerPin, 2500, 5000);   // tone(pin, frequency, duration), here sound buzzer at 2500 Hz for 5 seconds
        incorrectAttempts = 0;  // Reset the number of incorrect attempts
      } else {      // Password incorrect
        incorrectAttempts++;
        if (incorrectAttempts == 3) {    // 3 incorrect attempts to sound intruder alarm and close the lock.
          lcd.clear();
          lcd.print("Incorrect!");
          lcd.setCursor(0, 1);
          lcd.print("3 Attempts");
          delay(2000);
          lcd.clear();
          lcd.print("System Locked");
          tone(buzzerPin, 1500, 2000);
          delay(10000);
          incorrectAttempts = 0;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Enter Password: ");
        } else {    // Incorrect attempt, display appropriate message and ask for re-entry.
          lcd.clear();
          lcd.print("Incorrect!");
          lcd.setCursor(0, 1);
          lcd.print("Attempts:");
          lcd.print(incorrectAttempts);
          delay(2000);
          for (int i = 0; i < sizeof(pass); i++) {   // Clear buffer.
            pass[i] = '\0';
          }
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Enter Password:");
        }
      }
    }
  }
}
