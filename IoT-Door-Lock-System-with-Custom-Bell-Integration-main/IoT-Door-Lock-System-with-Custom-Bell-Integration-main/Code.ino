#define BLYNK_TEMPLATE_ID "TMPL3LcYWrt-k" 
#define BLYNK_TEMPLATE_NAME "Door" 
#define CAMERA_MODEL_AI_THINKER 
#include "FS.h" 
#include "SD_MMC.h" 
#include "camera_pins.h" 
#include "esp_camera.h" 
#include <WiFi.h> 
#include <WebServer.h> 
#include <BlynkSimpleEsp32.h> 
#include <ESP32Servo.h> 
char ssid[] = "Hitu"; 
char pass[] = "hitesh123"; 
char auth[] = "9tSFCuTHsWi9N0I-MgdhZ69L-yl13wKc"; 
const int ledPin = 4; 
const int servoPin = 13; 
const char *password = "abc123@"; 
Servo servoMotor; 
bool doorLocked = true; 
bool flashOn = false; 
WebServer server(80); 
void setup() { 
Serial.begin(115200); 
pinMode(ledPin, OUTPUT);
  // Initialize SD card, camera, WiFi, Blynk, and start the web server 
  if (!initComponents()) { 
    Serial.println("Initialization failed. Check your settings."); 
    return; 
  } 
 
  // Initialize the web server route for the image 
  server.on("/image.jpg", HTTP_GET, handleImageRequest); 
 
  // Start the web server 
  server.begin(); 
} 
 
void loop() { 
  Blynk.run(); 
  server.handleClient(); // Handle incoming HTTP requests 
} 
 
bool initComponents() { 
  // Initialize SD card 
  if (!SD_MMC.begin()) { 
    Serial.println("Card Mount Failed"); 
    return false; 
  } 
 
  uint8_t cardType = SD_MMC.cardType(); 
  if (cardType == CARD_NONE) { 
    Serial.println("No SD card attached"); 
    return false; 
  } 
Serial.println("SD card initialized successfully"); 
// Camera initialization 
camera_config_t config; 
config.ledc_channel = LEDC_CHANNEL_0; 
config.ledc_timer = LEDC_TIMER_0; 
config.pin_d0 = Y2_GPIO_NUM; 
config.pin_d1 = Y3_GPIO_NUM; 
config.pin_d2 = Y4_GPIO_NUM; 
config.pin_d3 = Y5_GPIO_NUM; 
config.pin_d4 = Y6_GPIO_NUM; 
config.pin_d5 = Y7_GPIO_NUM; 
config.pin_d6 = Y8_GPIO_NUM; 
config.pin_d7 = Y9_GPIO_NUM; 
config.pin_xclk = XCLK_GPIO_NUM; 
config.pin_pclk = PCLK_GPIO_NUM; 
config.pin_vsync = VSYNC_GPIO_NUM; 
config.pin_href = HREF_GPIO_NUM; 
config.pin_sscb_sda = SIOD_GPIO_NUM; 
config.pin_sscb_scl = SIOC_GPIO_NUM; 
config.pin_pwdn = PWDN_GPIO_NUM; 
config.pin_reset = RESET_GPIO_NUM; 
config.xclk_freq_hz = 20000000; 
config.pixel_format = PIXFORMAT_JPEG; 
config.frame_size = FRAMESIZE_UXGA; 
config.jpeg_quality = 12; 
config.fb_count = 1; 
esp_err_t err = esp_camera_init(&config); 
if (err != ESP_OK) { 
Serial.printf("Camera init failed with error 0x%x", err);
 return false; 
  } 
 
  // Connect to WiFi 
  WiFi.begin(ssid, pass); 
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.println("Connecting to WiFi..."); 
  } 
  Serial.println("Connected to WiFi"); 
 
  // Print ESP32-CAM IP address 
  Serial.print("IP Address: "); 
  Serial.println(WiFi.localIP()); 
 
  // Initialize Blynk 
  Blynk.begin(auth, ssid, pass); 
 
  return true; 
} 
 
void handleImageRequest() { 
  File file = SD_MMC.open("/image.jpg", FILE_READ); 
  if (!file) { 
    server.send(404, "text/plain", "File not found"); 
    return; 
  } 
 
  server.streamFile(file, "image/jpeg"); 
  file.close(); 
} 

BLYNK_WRITE(V1) { 
  int buttonState = param.asInt(); 
  if (buttonState == 1) { 
    if (!flashOn) { 
      digitalWrite(ledPin, HIGH); // Turn on flash 
      delay(500);                 // Wait for 0.5 seconds 
      digitalWrite(ledPin, LOW);  // Turn off flash 
      flashOn = true; 
    } 
    captureAndSavePhoto(); 
    Blynk.virtualWrite(V1, 0); // Reset button state 
    Blynk.virtualWrite(V1, 1); // Trigger an update of the Image Gallery widget 
  } else { 
    flashOn = false; 
  } 
} 
 
void captureAndSavePhoto() { 
  camera_fb_t *fb = esp_camera_fb_get(); 
  if (!fb) { 
    Serial.println("Camera capture failed"); 
    return; 
  } 
 
  // Save the image to the SD card 
  fs::FS &fs = SD_MMC; 
  File file = fs.open("/image.jpg", FILE_WRITE); 
  if (!file) { 
    Serial.println("Failed to open file for writing"); 
    return;
} 
f
 ile.write(fb->buf, fb->len); 
f
 ile.close(); 
esp_camera_fb_return(fb); 
} 
BLYNK_WRITE(V0) { 
String passwordInput = param.asStr(); 
if (passwordInput.equals(password) && doorLocked) { 
doorUnlock(); 
} 
} 
void doorUnlock() { 
digitalWrite(ledPin, HIGH);    // Turn LED on (optional, can be used for visual indication) 
servoMotor.attach(servoPin);   // Attach servo motor 
servoMotor.write(180);         
// Move the servo to 180 degrees (unlock) 
Blynk.virtualWrite(V0, "Door is unlocked!"); 
delay(6000);                   
servoMotor.write(0);           
// Wait for 5 seconds (you can change this value) 
// Move the servo back to 0 degrees (lock) 
digitalWrite(ledPin, LOW);     // Turn LED off (optional) 
Blynk.virtualWrite(V0, "Door is locked!"); 
doorLocked = false;            
// Reset doorLocked to false 
delay(2000);  // Delay to allow the notification to be sent before resetting the label 
doorLocked = true;      // Clear the input field in the Blynk app 
}



