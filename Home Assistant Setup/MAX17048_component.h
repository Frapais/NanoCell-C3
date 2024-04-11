#include "esphome.h"

#define MAX17048_ADDRESS        0x36
#define MAX17048_VCELL          0x02 // voltage
#define MAX17048_SOC            0x04 // percentage
#define MAX17048_MODE           0x06
#define MAX17048_VERSION        0x08
#define MAX17048_CONFIG         0x0c
#define MAX17048_COMMAND        0xfe
#define MAX17048_RATE           0x16 // rate

class MAX17048Sensor : public PollingComponent, public Sensor {
 public:
  Sensor *voltage_sensor = new Sensor();
  Sensor *percentage_sensor = new Sensor();
  Sensor *rate_sensor = new Sensor();

  MAX17048Sensor() : PollingComponent(60000) {}

  void setup() override {
    ESP_LOGD("custom", "Starting up MAX17048 sensor");

    Wire.begin();
  }

  uint16_t read16(uint8_t reg) {
      uint16_t temp;
      Wire.begin();
      Wire.beginTransmission(MAX17048_ADDRESS);
      Wire.write(reg);
      Wire.endTransmission();
      Wire.requestFrom(MAX17048_ADDRESS, 2);
      temp = (uint16_t)Wire.read() << 8;
      temp |= (uint16_t)Wire.read();
      Wire.endTransmission();
      return temp;
  }

  void update() override {
    float voltage = (float)(read16(MAX17048_VCELL)) * 78.125 / 1000000;
    voltage_sensor->publish_state(voltage);

    uint16_t percentage_tmp = read16(MAX17048_SOC);
    float percentage = (float)(percentage_tmp) / 256;
    percentage_sensor->publish_state(percentage);
    
    float rate = (float)(read16(MAX17048_RATE) * 0.208 / 10000);
    rate_sensor->publish_state(rate);
  }
};