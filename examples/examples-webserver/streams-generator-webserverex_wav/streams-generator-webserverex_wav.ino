/**
 * @file streams-generator-server_wav.ino
 *
 *  This sketch generates a test sine wave. The result is provided as WAV stream which can be listened to in a Web Browser
 *
 * @author Phil Schatzmann
 * @copyright GPLv3
 * 
 */

#include "AudioTools.h"
#include "AudioLibs/AudioServerEx.h"

// WIFI
const char *ssid = "Phil Schatzmann";
const char *password = "sabrina01";
const int sample_rate = 10000;
const int channels = 1;

SineWaveGenerator<int16_t> sineWave;            // Subclass of SoundGenerator with max amplitude of 32000
GeneratedSoundStream<int16_t> in(sineWave);     // Stream generated from sine wave
AudioWAVServerEx server;
StreamCopy copier(server, in);  // copy mic to tfl


void setup() {
  Serial.begin(115200);
  AudioLogger::instance().begin(Serial,AudioLogger::Info);
  HttpLogger.setLevel(tinyhttp::Info);

  // start server
  auto cfg = server.defaultConfig();
  cfg.sample_rate = sample_rate;
  cfg.channels = channels;
  cfg.ssid = ssid;
  cfg.password = password; 
  server.begin(cfg);

  // start generation of sound
  sineWave.begin(channels, sample_rate, N_B4);
  in.begin();
}


// copy the data
void loop() {
  copier.copy();
}
