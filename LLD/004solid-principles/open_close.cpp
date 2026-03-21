// Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification. 

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// NotificationChannel interface
class NotificationChannel {
public:
    virtual ~NotificationChannel() = default;
    virtual void send(const string& message) const = 0;
};

// Concrete channels
class EmailChannel : public NotificationChannel {
public:
    void send(const string& message) const override {
        cout << "Sending EMAIL: " << message << endl;
    }
};

class SMSChannel : public NotificationChannel {
public:
    void send(const string& message) const override {
        cout << "Sending SMS: " << message << endl;
    }
};

class PushChannel : public NotificationChannel {
public:
    void send(const string& message) const override {
        cout << "Sending PUSH: " << message << endl;
    }
};

class SlackChannel : public NotificationChannel {
public:
    void send(const string& message) const override {
        cout << "Sending SLACK: " << message << endl;
    }
};

// Refactored service - no if-else
class NotificationService {
private:
    vector<unique_ptr<NotificationChannel>> channels;
public:
    NotificationService(vector<unique_ptr<NotificationChannel>> channels)
        : channels(move(channels)) {}

    void sendNotification(const string& message) const {
        for (const auto& channel : channels) {
            channel->send(message);
        }
    }
};

int main() {
    vector<unique_ptr<NotificationChannel>> channels;
    channels.push_back(make_unique<EmailChannel>());
    channels.push_back(make_unique<SMSChannel>());
    channels.push_back(make_unique<PushChannel>());
    channels.push_back(make_unique<SlackChannel>());

    NotificationService service(move(channels));
    service.sendNotification("Your order has shipped!");

    return 0;
}
