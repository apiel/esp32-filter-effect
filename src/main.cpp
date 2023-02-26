#include <Arduino.h>
#include <Wire.h>

// #define AUDIOKIT_BOARD 1

#include "AudioKitHAL.h"
#include "SineWaveGenerator.h"

AudioKit kit;
SineWaveGenerator wave;
const int BUFFER_SIZE = 1024;
uint8_t buffer[BUFFER_SIZE];

void setup()
{
  LOGLEVEL_AUDIOKIT = AudioKitInfo;
  Serial.begin(115200);
  // open in write mode
  // auto cfg = kit.defaultConfig(AudioOutput);

  auto cfg = kit.defaultConfig();
  // cfg.adc_input = AUDIO_HAL_ADC_INPUT_ALL;
  cfg.adc_input = AUDIO_HAL_ADC_INPUT_LINE1;
  cfg.sample_rate = AUDIO_HAL_16K_SAMPLES;

  kit.begin(cfg);

  // 1000 hz
  // wave.setFrequency(1000);
  // wave.setSampleRate(cfg.sampleRate());
}

void loop()
{
  // size_t len = wave.read(buffer, BUFFER_SIZE);
  size_t len = kit.read(buffer, BUFFER_SIZE);

  // HERE will be some code to apply filters

  kit.write(buffer, len);
}