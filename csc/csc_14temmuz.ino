#include "MPU9250.h"
#include <esp_now.h>
#include <WiFi.h>


#ifdef defined(SAMD)
 #define SerialPort SerialUSB
#else
  #define SerialPort Serial
#endif
// esp dürbünün mac adresi gelecek



uint8_t broadcastAddress1[]={0x3C, 0x61, 0x05, 0x2A, 0xFB, 0x74};

MPU9250 mpu;
float Yaw,Pitch,Roll;


typedef struct struct_message  {

    int Yaw;
    int Pitch;
    int Roll;
    

} struct_message ;

struct_message myData;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  // troubleshooting bitince printleri kaldır.
  char macStr[18];
  Serial.print("\r\nPaket gönderimi:\t");
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x", mac_addr[0],mac_addr[1],mac_addr[2],mac_addr[3],mac_addr[4],mac_addr[5]);
  Serial.print(macStr);
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
    }

void setup() {
  SerialPort.begin(115200);
  Wire.begin();
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP_now hatası");
    return;
  }

esp_now_register_send_cb(OnDataSent);

esp_now_peer_info_t peerInfo;
peerInfo.channel=0;
peerInfo.encrypt=false;

memcpy(peerInfo.peer_addr, broadcastAddress1, 6);
if (esp_now_add_peer(&peerInfo)!=ESP_OK){
  Serial.println("alıcı eklenemedi");
  return;}
        if (!mpu.setup(0x68)) {  // change to your own address
        while (1) {
            Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
            
            delay(5000);
        }
    }
}


void loop() {
mpu.update();
myData.Yaw=mpu.getYaw();
myData.Pitch=mpu.getPitch();
myData.Roll=mpu.getRoll();
esp_err_t result= esp_now_send(0, (uint8_t *) &myData, sizeof(struct_message));
delay(125);
}
