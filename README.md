# Arduino Audio Tools

Some basic __header-only C++ classes__ that can be used for __Audio Processing__ provided as __Arduino and cmake C++ Library__:

- We provide different "Audio Sources" and "Audio Sinks" (see next section)
- Support for different [Encoders](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_audio_encoder.html) and [Decoders](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_audio_decoder.html) for MP3, AAC, WAV, FLAC, etc for [EncodedAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_encoded_audio_stream.html)
- Different [Sound Generators](https://pschatzmann.github.io/arduino-audio-tools/group__generator.html) (e.g. to generate a sine tone) for [GeneratedSoundStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_generated_sound_stream.html)
- Support for [Sound Effects](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_audio_effect_stream.html) with different [Effect Implementations](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_audio_effect.html) (e.g. Boost, Distortion, Echo, Reverb...) for [AudioEffectStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_audio_effect_stream_t.html)
- Different [Buffer Implementations](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_base_buffer.html) for [QueueStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_queue_stream.html)
- Different [Converters](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_base_converter.html) for [ConverterStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_converter_stream.html)
- Different [Filters](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_filter.html) for [FilteredStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_filtered_stream.html)
- [Musical Notes](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_musical_notes.html) (with frequencies of notes)
- A [Repeating Timer](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_timer_alarm_repeating.html) (e.g. for sampling audio data using exact times) for [TimerCallbackAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_timer_callback_audio_stream.html)
- Desktop Integration: Building of Arduino Audio Sketches to be run on [Linux, Windows and OS/X](https://github.com/pschatzmann/arduino-audio-tools/wiki/Running-an-Audio-Sketch-on-the-Desktop)

This functionality provides the glue which makes different audio processing components and libraries work together.
We also provide [plenty of examples](https://github.com/pschatzmann/arduino-audio-tools/wiki/Examples) that demonstrate how to implement the different scenarios. The __design philosophy__ is based on the Arduino conventions: we use the ```begin()``` and ```end()``` methods to start and stop the processing and we propagate the __use of Streams__.  We all know the [Arduino Streams](https://pschatzmann.github.io/arduino-audio-tools/class_stream.html): We usually use them to write out print messages and sometimes we use them to read the output from Serial devices. The same thing applies to “Audio Streams”: You can read audio data from “Audio Sources” and you write them to “Audio Sinks”.

As “Audio Sources” we will have e.g.:

- Digital Microphones – [I2SStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_i2_s_stream.html)
- Analog Microphones – [AnalogAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_analog_audio_stream.html)
- Files on the Internet – [URLStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_u_r_l_stream.html)
- Streaming Internet Radios - [ICYStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_i_c_y_stream.html)
- Generated Sound – [GeneratedSoundStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_generated_sound_stream.html)
- Encoded Audio - [EncodedAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_encoded_audio_stream.html)
- Mobile Phone A2DP Bluetooth – [A2DPStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_a2_d_p_stream.html)
- Binary Data in Flash Memory – [MemoryStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_memory_stream.html)
- Audio generated by STK Framwork - [STKStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_s_t_k_stream.html)
- Desktop Integration - [PortAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_port_audio_stream.html) [MiniAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_mini_audio_stream.html) [StdioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_stdio_stream.html)
- A Timer based Source - [TimerCallbackAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_timer_callback_audio_stream.html)
- ESP32 Lyrat/AudioKit - [AudioKitStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_audio_kit_stream.html)
- Input using FIR, IIR Filters - [FilteredStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_filtered_stream.html)
- Tensorflow Lite - [TfLiteAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_tf_lite_audio_stream.html)
- [Converting Streams](https://pschatzmann.github.io/arduino-audio-tools/group__transform.html)
- Communication - [ESPNowStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_e_s_p_now_stream.html), [UDPStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_u_d_p_stream.html)
- Any other Arduino Classes implementing Streams: SD, Ethernet etc

As “Audio Sinks” we will have e.g:

- external DAC – [I2SStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_i2_s_stream.html)
- Analog output e.g. to an Amplifier – [AnalogAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_analog_audio_stream.html)
- Output using PWM – [PWMAudioOutput](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_p_w_m_audio_output.html)
- Output to SPDIF/TOSLINK - [SPDIFOutput](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_s_p_d_i_f_output.html)
- Encoded Audio - [EncodedAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_encoded_audio_stream.html)
- Bluetooth Speakers – [A2DPStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_a2_d_p_stream.html)
- Serial to display the data as CSV – [CsvOutput](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_csv_output.html)
- Serial to display the data as hex dump - [HexDumpOutput](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_hex_dump_output.html)
- Encoding and Decoding of Audio [EncodedAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_encoded_audio_stream.html)
- Desktop Integration - [PortAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_port_audio_stream.html) [MiniAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_mini_audio_stream.html) [StdioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_stdio_stream.html)
- ID3 Metadata for MP3 - [MetaDataID3](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_meta_data_i_d3.html)
- A Timer based Sink - [TimerCallbackAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_timer_callback_audio_stream.html)
- ESP32 Lyrat/AudioKit - [AudioKitStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_audio_kit_stream.html)
- VS1053 Codec Module - [VS1053Stream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_v_s1053_stream.html)
- Callback integration e.g. with ESP8266Audio [AudioOutputWithCallback](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_audio_output_with_callback.html) 
- Output using FIR, IRR Filters - [FilteredStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_filtered_stream.html)
- Determine the Volume - [VolumeOutput](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_volume_output.html)
- Split the Output to different Destinations - [MultiOutput](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_multi_output.html)
- 3 Band Equilizer - [Equilizer3Bands](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_equilizer3_bands.html)
- FFT - [AudioRealFFT](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_audio_real_f_f_t.html) and [AudioKissFFT](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_audio_kiss_f_f_t.html)
- Tensorflow Lite - [TfLiteAudioStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_tf_lite_audio_stream.html)
- [Converting Streams](https://pschatzmann.github.io/arduino-audio-tools/group__transform.html)
- Communication - [ESPNowStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_e_s_p_now_stream.html), [UDPStream](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_u_d_p_stream.html)
- Multiuser-Webserver for PCM Output - [AudioWAVServerEx](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_audio_w_a_v_server_ex.html)
- Any other Arduino Classes implementing Streams: SD, Ethernet etc

### Examples

Here is an simple example which streams a file from the Flash Memory and writes it to I2S: 

```C++
#include "AudioTools.h"
#include "StarWars30.h"

uint8_t channels = 2;
uint16_t sample_rate = 22050;

MemoryStream music(StarWars30_raw, StarWars30_raw_len);
I2SStream i2s;  // Output to I2S
StreamCopy copier(i2s, music); // copies sound into i2s

void setup(){
    Serial.begin(115200);

    auto config = i2s.defaultConfig(TX_MODE);
    config.sample_rate = sample_rate;
    config.channels = channels;
    config.bits_per_sample = 16;
    i2s.begin(config);
}

void loop(){
    copier.copy();
}

```
Each stream has it's own [configuration object](https://pschatzmann.github.io/arduino-audio-tools/structaudio__tools_1_1_audio_info.html) that should be passed to the begin method. The defaultConfig() method is providing a default proposal which will usually "just work". Please consult 
the [class documentation](https://pschatzmann.github.io/arduino-audio-tools/modules.html) for the available configuration parameters. You can also __easily adapt__ any provided examples: If you e.g. replace the I2SStream with the AnalogAudioStream class, you will get analog instead of digital output.

I suggest you continue to read the more [detailed introduction](https://github.com/pschatzmann/arduino-audio-tools/wiki/Introduction).

Further examples can be found in the [Wiki](https://github.com/pschatzmann/arduino-audio-tools/wiki/Examples). 

Dependent on the example you might need to install some [addional libaries](https://github.com/pschatzmann/arduino-audio-tools/wiki/Optional-Libraries)

### AudioPlayer

The library also provides a versatile [AudioPlayer](https://pschatzmann.github.io/arduino-audio-tools/classaudio__tools_1_1_audio_player.html). Further information can be found in the [Wiki](https://github.com/pschatzmann/arduino-audio-tools/wiki/The-Audio-Player-Class)


### Logging

The application uses a built in logger (see AudioLogger.h and AudioConfig.h). You can  e.g. deactivate the logging by changing USE_AUDIO_LOGGING to false in the AudioConfig.h: 

```C++
#define USE_AUDIO_LOGGING false
#define LOG_LEVEL AudioLogger::Warning
#define LOG_STREAM Serial
```

Per default we use the log level warning and the logging output is going to Serial. You can also change this in your sketch by calling AudioLogger begin with the output stream and the log level e.g:

```C++
AudioLogger::instance().begin(Serial, AudioLogger::Debug);
```


## Show and Tell

Get some inspiration [from projects that were using this library](https://github.com/pschatzmann/arduino-audio-tools/discussions/categories/show-and-tell) or share your projects with the community.


## Documentation

Please use this before you raise any issue or start a discussion!

- Read the [Documentation in the Wiki](https://github.com/pschatzmann/arduino-audio-tools/wiki)
- Check the [Class Documentation by Topic](https://pschatzmann.github.io/arduino-audio-tools/modules.html). 
- Find your class in [All Classes Alphabetically](https://pschatzmann.github.io/arduino-audio-tools/namespaceaudio__tools.html)
- You also might find further information in [one of my Blogs](https://www.pschatzmann.ch/home/category/machine-sound/)


## Installation in Arduino

You can download the library as zip and call include Library -> zip library. Or you can git clone this project into the Arduino libraries folder e.g. with

```
cd  ~/Documents/Arduino/libraries
git clone pschatzmann/arduino-audio-tools.git
```

I recommend to use git because you can easily update to the latest version just by executing the ```git pull``` command in the project folder.
If you want to use the library in PlatformIO, you can find a [detailed description in the Wiki](https://github.com/pschatzmann/arduino-audio-tools/wiki/Working-with-PlatformIO).


## Sponsor Me

This software is totally free, but you can make me happy by rewarding me with a treat

- [Buy me a coffee](https://www.buymeacoffee.com/philschatzh)
- [Paypal me](https://paypal.me/pschatzmann?country.x=CH&locale.x=en_US)
