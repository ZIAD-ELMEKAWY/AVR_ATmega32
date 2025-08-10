#define BLYNK_TEMPLATE_ID "TMPL5Kph4g9H5"
#define BLYNK_TEMPLATE_NAME "Smart Home"
#define BLYNK_AUTH_TOKEN "OohOpBBJ027wHj4mNx2bYMASSzrpzuH6"  // Blynk Auth Token

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal_I2C.h>

// Include FreeRTOS headers
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;
// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
HardwareSerial SerialPort(2);

char ssid[] = "WIFI_SSID";
char pass[] = "WIFI_PASSWORD";
#define RX2   16
#define TX2   17
int valueFromBlynkv3 = 0;
int valueFromBlynkv4 = 0 ;
String incomingData = "";
int sensor1, sensor2, sensor3;
char count = 0 ;

// Function prototypes for FreeRTOS tasks
void TaskBlynk(void *pvParameters);
void TaskSerial(void *pvParameters);
void TaskLCD(void *pvParameters);
void LCD_Display(void);
void handleSensorData(String data);

BLYNK_WRITE(V3) {
  valueFromBlynkv3 = param.asInt();  // Read value from Blynk Virtual Pin V0
  if (valueFromBlynkv3 == HIGH)
  {
    Serial2.println(1);
    Serial.println("light high");
  }
  else if (valueFromBlynkv3 == LOW)
  {
    Serial2.println(0);
    Serial.println("light low");
  }
}

BLYNK_WRITE(V4) {
  valueFromBlynkv4 = param.asInt();  // Read value from Blynk Virtual Pin V0
  if (valueFromBlynkv4 == HIGH)
  {
    Serial2.println(3);
    Serial.println("fan high");
  }
  else if (valueFromBlynkv4 == LOW)
  {
    Serial2.println(2);
    Serial.println("fan low");
  }
}

void setup() {
  Serial.begin(9600); // Debug
  Serial2.begin(9600, SERIAL_8N1, 16, 17);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();

  // Create FreeRTOS tasks
  // Task 1 : Priority Zero (Highest)
  xTaskCreate(
    TaskBlynk,          // Function that implements the task.
    "BlynkTask",        // Text name for the task.
    10000,              // Stack size in words, not bytes.
    NULL,               // Parameter passed into the task.
    0,                  // Priority at which the task is created.
    NULL);              // Used to pass out the created task's handle.

  // Task 2 : Priority one
  xTaskCreate(
    TaskSerial,
    "SerialTask",
    4096,
    NULL,
    1,
    NULL);

  // Task 3 : Priority two (Lowest)
  xTaskCreate(
    TaskLCD,
    "LCDTask",
    2048,
    NULL,
    2,
    NULL);
}

// FreeRTOS scheduler will take over, loop() will not be used
void loop() 
{
  // The FreeRTOS scheduler takes control from here.
  // This loop() function is no longer needed.
}

// Task function definitions
void TaskBlynk(void *pvParameters) {
  for (;;) {
    Blynk.run();
    vTaskDelay(10 / portTICK_PERIOD_MS); // Run Blynk every 10ms
  }
}

void TaskSerial(void *pvParameters) {
  for (;;) {
    while (Serial2.available()) 
    {
      char c = Serial2.read();
      if (c == '\n') {
        handleSensorData(incomingData);
        incomingData = "";
      } else {
        incomingData += c;
      }
    }
    vTaskDelay(10 / portTICK_PERIOD_MS); // Check for serial data every 10ms
  }
}

void TaskLCD(void *pvParameters) {
  for (;;) {
    LCD_Display();
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Update LCD every second
  }
}

void handleSensorData(String data) 
{
  if (sscanf(data.c_str(), "%d,%d,%d", &sensor1, &sensor2, &sensor3) == 3) {
    Serial.printf("Parsed: %d, %d, %d\n", sensor1, sensor2, sensor3);
    Blynk.virtualWrite(V0, sensor1);
    Blynk.virtualWrite(V1, sensor2);
    Blynk.virtualWrite(V2, sensor3);
  } else {
    Serial.println("Parsing failed!");
  }
}

void LCD_Display(void)
{
  lcd.clear();
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  lcd.print("Tempe : ");
  lcd.setCursor(8, 0);
  lcd.print(sensor1);
  // set cursor to first column, second row
  lcd.setCursor(0, 1);
  lcd.print("Light : ");
  lcd.setCursor(8, 1);
  lcd.print(sensor2);
}
