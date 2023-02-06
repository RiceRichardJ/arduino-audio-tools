
#include "AudioTools.h"
#include "AudioLibs/AudioRealFFT.h" // using RealFFT

AudioRealFFT fft; // or AudioKissFFT
SineWaveGenerator<int16_t> sineWave(32000);
GeneratedSoundStream<int16_t> in(sineWave);
StreamCopy copier(fft, in);
uint16_t sample_rate = 44100;
int bits_per_sample = 16;
int channels = 1;
float value = 0;

// check fft result
void fftResult(AudioFFTBase &fft) {
    // build result array
    AudioFFTResult all[fft.size()];
    for (int j=0;j<fft.size();j++){
        all[j].bin = j;
        all[j].magnitude = fft.magnitude(j);
        all[j].frequency = fft.frequency(j);
    }
    // sort descending
    std::sort(all, all + fft.size(), [](AudioFFTResult a, AudioFFTResult b){ return a.magnitude > b.magnitude; });

    // get top 5
    AudioFFTResult topn[5];
    fft.resultArray(topn);

    // check the topn with sorted result
    for (int j=0;j<5;j++){
        Serial.print(all[j].bin);
        Serial.print(":");
        Serial.print(topn[j].bin);
        Serial.print(" ");
        //assert(all[j].bin==topn[j].bin);
    }
    Serial.println();

}

void setup() {
  Serial.begin(115200);
  AudioLogger::instance().begin(Serial, AudioLogger::Warning);

  // set the frequency
  sineWave.setFrequency(N_B4);

  // Setup sine wave
  auto cfg = in.defaultConfig();
  cfg.channels = channels;
  cfg.sample_rate = sample_rate;
  in.begin(cfg);

  // Setup FFT
  auto tcfg = fft.defaultConfig();
  tcfg.copyFrom(cfg);
  tcfg.length = 4096;
  tcfg.callback = &fftResult;
  fft.begin(tcfg);
}

void loop() { copier.copy(); }
