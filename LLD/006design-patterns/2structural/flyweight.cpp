// FLYWEIGHT:  efficiently sharing common parts of objects so as to reduce space
// Ex: particle system

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
using namespace std;

struct ParticleType {
	string texture;
	string color;
	ParticleType(string t, string c) : texture(move(t)), color(move(c)) {}
};

struct ParticleTypeFactory {
	unordered_map<string, shared_ptr<ParticleType>> cache;
	shared_ptr<ParticleType> get(const string& texture, const string& color) {
		string key = texture + "|" + color;
		if (!cache.count(key)) cache[key] = make_shared<ParticleType>(texture, color);
		return cache[key];
	}
};

struct Particle {
	int x, y;
	shared_ptr<ParticleType> type;
	Particle(int px, int py, shared_ptr<ParticleType> t) : x(px), y(py), type(move(t)) {}
	void draw() const {
		cout << type->texture << ' ' << type->color << ' ' << x << ' ' << y << '\n';
	}
};

int main() {
	ParticleTypeFactory factory;
	auto smoke = factory.get("circle", "gray");
	Particle p1(1, 2, smoke), p2(3, 4, smoke);
	p1.draw();
	p2.draw();
}