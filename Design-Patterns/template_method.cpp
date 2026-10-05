#include <iostream>

class DataMiner {
public:
    virtual ~DataMiner() = default;
    void mine(const std::string& path) {
        openFile(path);
        extractData();
        parseData();
        closeFile();
    }
protected:
    virtual void openFile(const std::string& path) = 0;
    virtual void extractData() = 0;
    virtual void parseData() = 0;
    void closeFile() { std::cout << "File closed successfully\n"; }
};

class CSVDataMiner : public DataMiner {
protected:
    void openFile(const std::string& path) override { std::cout << "Opening CSV: " << path << "\n"; }
    void extractData() override { std::cout << "Extracting raw lines\n"; }
    void parseData() override { std::cout << "Parsing comma-separated fields\n"; }
};

int main() {
    CSVDataMiner miner;
    miner.mine("data.csv");
    return 0;
}
