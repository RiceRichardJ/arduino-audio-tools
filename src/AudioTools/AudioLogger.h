#pragma once

#include "AudioConfig.h"
#include "Stream.h"

// Logging Implementation
#if USE_AUDIO_LOGGING

namespace audio_tools {

/**
 * @brief A simple Logger that writes messages dependent on the log level
 * @author Phil Schatzmann
 * @copyright GPLv3
 * 
 */
class AudioLogger {
    public:
        /**
         * @brief Supported log levels. You can change the default log level with the help of the PICO_LOG_LEVEL define.
         * 
         */
        enum LogLevel { 
            Debug,
            Info, 
            Warning, 
            Error
        };

        /// activate the logging
        void begin(Stream& out, LogLevel level=LOG_LEVEL) {
            this->log_stream_ptr = &out;
            this->log_level = level;
        }

        /// checks if the logging is active
        bool isLogging(LogLevel level = Info){
            return log_stream_ptr!=nullptr && level >= log_level;
        }

        AudioLogger &prefix(const char* file, int line, LogLevel current_level){
            printPrefix(file,line,current_level);
            return *this;
        }

        void println(){
            log_stream_ptr->println(print_buffer);
            print_buffer[0]=0;
        }

        char* str() {
            return print_buffer;
        }

        /// provides the singleton instance
        static AudioLogger &instance(){
            static AudioLogger *ptr;
            if (ptr==nullptr){
                ptr = new AudioLogger;
            }
            return *ptr;
        }

        LogLevel level() {
            return log_level;
        }


    protected:
        Stream *log_stream_ptr = &LOG_STREAM;
        const char* TAG = "AudioTools";
        LogLevel log_level = LOG_LEVEL;
        char print_buffer[PRINTF_BUFFER_SIZE];

        AudioLogger() {}

        const char* levelName(LogLevel level) const {
            switch(level){
                case Debug:
                    return "D";
                case Info:
                    return "I";
                case Warning:
                    return "W";
                case Error:
                    return "E";
            }
            return "";
        }

        int printPrefix(const char* file, int line, LogLevel current_level) const {
            const char* file_name = strrchr(file, '/') ? strrchr(file, '/') + 1 : file;
            const char* level_code = levelName(current_level);
            int len = log_stream_ptr->print("[");
            len += log_stream_ptr->print(level_code);
            len += log_stream_ptr->print("] ");
            len += log_stream_ptr->print(file_name);
            len += log_stream_ptr->print(" : ");
            len += log_stream_ptr->print(line);
            len += log_stream_ptr->print(" - ");
            return len;
        }

};

}    

#define LOG_OUT(level, ...) snprintf(audio_tools::AudioLogger::instance().prefix(__FILE__,__LINE__, level).str(),PRINTF_BUFFER_SIZE,__VA_ARGS__); audio_tools::AudioLogger::instance().println();

#define LOGD(...) if (audio_tools::AudioLogger::instance().level()<=audio_tools::AudioLogger::Debug) { LOG_OUT(audio_tools::AudioLogger::Debug, __VA_ARGS__);}
#define LOGI(...) if (audio_tools::AudioLogger::instance().level()<=audio_tools::AudioLogger::Info) { LOG_OUT(audio_tools::AudioLogger::Info, __VA_ARGS__);}
#define LOGW(...) if (audio_tools::AudioLogger::instance().level()<=audio_tools::AudioLogger::Warning) { LOG_OUT(audio_tools::AudioLogger::Warning, __VA_ARGS__);}
#define LOGE(...) if (audio_tools::AudioLogger::instance().level()<=audio_tools::AudioLogger::Error) { LOG_OUT(audio_tools::AudioLogger::Error, __VA_ARGS__);}

#else

#define LOGD(...) 
#define LOGI(...) 
#define LOGW(...) 
#define LOGE(...) 

#endif
