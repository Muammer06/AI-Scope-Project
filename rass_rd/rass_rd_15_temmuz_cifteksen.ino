#include "MPU9250.h"
#include <esp_now.h>
#include <WiFi.h>
#include <AccelStepper.h>
#include "DecisionTree1.h"
#include "DecisionTree2.h"

Eloquent::ML::Port::DecisionTree1 X_eksen;
Eloquent::ML::Port::DecisionTree2 Y_eksen;

#ifdef defined(SAMD)
 #define SerialPort SerialUSB
#else
  #define SerialPort Serial
#endif
float imu_data[6];
int yaw_bacak, pitch_bacak, roll_bacak;
int hareket_Y,hareket_X;

AccelStepper stepper_Y(1,25,33);
AccelStepper stepper_X(1,27,26);
MPU9250 mpu;
float Yaw_durbun,Pitch_durbun,Roll_durbun;

typedef struct struct_message  {

    int Yaw;
    int Pitch;
    int Roll;

} struct_message ;

struct_message myData;


void onDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len){
memcpy(&myData, incomingData, sizeof(myData));
yaw_bacak=myData.Yaw;
pitch_bacak=myData.Pitch;
roll_bacak=myData.Roll;
imu_data[0]=Yaw_durbun;
imu_data[1]=Pitch_durbun;
imu_data[2]=Roll_durbun;
imu_data[3]=yaw_bacak;
imu_data[4]=pitch_bacak;
imu_data[5]=roll_bacak;
hareket_X=X_eksen.predict(imu_data);
hareket_Y=Y_eksen.predict(imu_data);  
 }



void setup() {
SerialPort.begin(115200);
WiFi.mode(WIFI_STA);
Wire.begin();
if (esp_now_init() != ESP_OK) {
    Serial.println("ESP_now hatasÄ±");
    return;}
esp_now_register_recv_cb(onDataRecv);
if (!mpu.setup(0x68)) {  // change to your own address
        while (1) {
            Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
            delay(5000);}}
stepper_Y.setMaxSpeed(200);
stepper_Y.setAcceleration(100);
stepper_X.setMaxSpeed(200);
stepper_X.setAcceleration(100);}

void loop() {
mpu.update();
Yaw_durbun=mpu.getYaw();
Pitch_durbun=mpu.getPitch();
Roll_durbun=mpu.getRoll();

    
  stepper_Y.moveTo(hareket_Y);
  stepper_X.moveTo(hareket_X);
  
    stepper_Y.run();
    stepper_X.run();
    
}
