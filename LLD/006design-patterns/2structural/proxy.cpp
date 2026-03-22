// PROXY: allows us to communicate to a more resource expensive object, cheaply
// Ex: caching before querying db

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct DataService {
	virtual string get(const string& key) = 0;
	virtual ~DataService() = default;
};

struct RealDataService : DataService {
	string get(const string& key) override {
		return "db:" + key;
	}
};

struct CachingProxy : DataService {
	RealDataService real;
	unordered_map<string, string> cache;
	string get(const string& key) override {
		if (!cache.count(key)) cache[key] = real.get(key);
		return cache[key];
	}
};

int main() {
	CachingProxy proxy;
	cout << proxy.get("user:1") << '\n';
	cout << proxy.get("user:1") << '\n';
}