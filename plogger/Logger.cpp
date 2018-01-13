//
// Created by pizzaman on 02/01/2018.
//

#include "Logger.h"

#include <iostream>

std::string LogLevel::toString(uint8_t level) {
    std::string content = "";
    switch (level) {
        case LogLevel::LOG_DEBUG:
            content = "DEBUG";
            break;
        case LogLevel::LOG_INFO:
            content = "INFO";
            break;
        case LogLevel::LOG_WARN:
            content = "WARN";
            break;
        case LogLevel::LOG_ERROR:
            content = "ERROR";
            break;
        case LogLevel::LOG_FATAL:
            content = "FATAL";
            break;
        default:
            content = "ALL";
    }

    return content;

}

AbstractLogger::AbstractLogger(const std::string &value) {
    name = value;
}

void AbstractLogger::debug(const std::string &message, ...) {
    va_list va;
    va_start(va, message);
    this->log(LogLevel::LOG_DEBUG, message, va);
    va_end(va);
}

void AbstractLogger::info(const std::string &message, ...) {
    va_list va;
    va_start(va, message);
    this->log(LogLevel::LOG_INFO, message, va);
    va_end(va);
}

void AbstractLogger::warn(const std::string &message, ...) {
    va_list va;
    va_start(va, message);
    this->log(LogLevel::LOG_WARN, message, va);
    va_end(va);
}

void AbstractLogger::error(const std::string &message, ...) {
    va_list va;
    va_start(va, message);
    this->log(LogLevel::LOG_ERROR, message, va);
    va_end(va);
}

void AbstractLogger::fatal(const std::string &message, ...) {
    va_list va;
    va_start(va, message);
    this->log(LogLevel::LOG_FATAL, message, va);
    va_end(va);
}