#include <bits/stdc++.h>
using namespace std;

/*
Interface -> What?
Class     -> How?
*/

// interface
class Formatter {
public:
    virtual ~Formatter() {}
    virtual string format(const string& message) = 0;
};

// class definition 1
class PlainFormatter : public Formatter {
public:
    string format(const string& message) override {
        return message;
    }
};

// class definition 2
class JsonFormatter : public Formatter {
public:
    string format(const string& message) override {
        return "{\"log\": \"" + message + "\"}";
    }
};

class Logger {
    Formatter* formatter;
public:
    Logger(Formatter* formatter) : formatter(formatter) {}

    void log(const string& message) {
        cout << formatter->format(message) << endl;
    }
};

int main() {
    PlainFormatter plain;
    Logger plainLogger(&plain);
    plainLogger.log("Server started on port 8080");

    JsonFormatter json;
    Logger jsonLogger(&json);
    jsonLogger.log("Server started on port 8080");

    return 0;
}