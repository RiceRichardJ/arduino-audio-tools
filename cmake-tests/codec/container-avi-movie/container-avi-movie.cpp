/**
 * @file communication-container-binary.ino
 * @author Phil Schatzmann
 * @brief generate sine wave -> encoder -> decoder -> audiokit (i2s)
 * @version 0.1
 * @date 2022-04-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "AudioTools.h"
#include "AudioCodecs/ContainerAVI.h"
#include "AudioLibs/Desktop/File.h"
#include "AudioLibs/PortAudioStream.h"
#include "JpegDisplayOpenCV.h"

PortAudioStream out;   // Output of sound on desktop 
JpegDisplayOpenCV jpegDisplay;
AVIDecoder codec(new DecoderL8(), &jpegDisplay);
EncodedAudioOutput avi(&out, &codec);
File file;
StreamCopy copier(avi, file);

void setup() {
  AudioLogger::instance().begin(Serial, AudioLogger::Info);
  file.open("/data/resources/test1.avi",FILE_READ);
  codec.setOutputVideoStream(jpegDisplay);
  codec.setMute(true);
}

void loop() {
  if(!copier.copy()){
    stop();
  }
}
