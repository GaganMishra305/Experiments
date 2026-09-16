#include <iostream>
#include <memory>

class CompressionStrategy {
public:
    virtual ~CompressionStrategy() = default;
    virtual void compress(const std::string& file) = 0;
};

class ZipCompression : public CompressionStrategy {
public:
    void compress(const std::string& file) override {
        std::cout << "Compressing " << file << " using ZIP\n";
    }
};

class GzipCompression : public CompressionStrategy {
public:
    void compress(const std::string& file) override {
        std::cout << "Compressing " << file << " using GZIP\n";
    }
};

class FileCompressor {
private:
    std::unique_ptr<CompressionStrategy> strategy_;
public:
    void setStrategy(std::unique_ptr<CompressionStrategy> strategy) {
        strategy_ = std::move(strategy);
    }
    void execute(const std::string& file) {
        if (strategy_) strategy_->compress(file);
    }
};

int main() {
    FileCompressor compressor;
    compressor.setStrategy(std::make_unique<ZipCompression>());
    compressor.execute("data.csv");
    compressor.setStrategy(std::make_unique<GzipCompression>());
    compressor.execute("data.csv");
    return 0;
}
