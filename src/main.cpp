#include <Arduino.h>
#include <Wire.h>

// #define AUDIOKIT_BOARD 1

#include "AudioKitHAL.h"

AudioKit kit;
const int BUFFER_SIZE = 1024;
uint8_t buffer[BUFFER_SIZE];

void setup()
{
  LOGLEVEL_AUDIOKIT = AudioKitWarning;
  Serial.begin(115200);

  auto cfg = kit.defaultConfig();
  cfg.adc_input = AUDIO_HAL_ADC_INPUT_LINE2;
  // cfg.sample_rate = AUDIO_HAL_48K_SAMPLES;
  // cfg.bits_per_sample = AUDIO_HAL_BIT_LENGTH_32BITS;

  kit.begin(cfg);
}

void loop()
{
  size_t len = kit.read(buffer, BUFFER_SIZE);

  // HERE will be some code to apply filters

  kit.write(buffer, len);
}