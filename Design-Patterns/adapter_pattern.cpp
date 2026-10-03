#include <iostream>
#include <memory>

class ModernPrinter {
public:
    virtual ~ModernPrinter() = default;
    virtual void printDocument(const std::string& text) = 0;
};

class LegacyPrinter {
public:
    void printOldFormat(const char* c_str) {
        std::cout << "[Legacy Printer Output]: " << c_str << "\n";
    }
};

class PrinterAdapter : public ModernPrinter {
private:
    LegacyPrinter legacy_;
public:
    void printDocument(const std::string& text) override {
        legacy_.printOldFormat(text.c_str());
    }
};

int main() {
    std::unique_ptr<ModernPrinter> printer = std::make_unique<PrinterAdapter>();
    printer->printDocument("Sales Report Q3");
    return 0;
}
