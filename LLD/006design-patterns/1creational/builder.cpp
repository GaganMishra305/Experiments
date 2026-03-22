// BUILDER: when there are too many parameters
// Ex: HttpBuilder, any complex object

#include <iostream>
#include <string>
using namespace std;

struct Meal {
    string drink, mainDish, dessert;
    string str() const { return drink + ", " + mainDish + ", " + dessert; }
};

struct MealBuilder {
    Meal meal;
    MealBuilder& withDrink(string d) { meal.drink = move(d); return *this; }
    MealBuilder& withMain(string m) { meal.mainDish = move(m); return *this; }
    MealBuilder& withDessert(string d) { meal.dessert = move(d); return *this; }
    Meal build() const { return meal; }
};

int main() {
    Meal m = MealBuilder().withDrink("Juice").withMain("Pasta").withDessert("Cake").build();
    cout << m.str() << '\n';
}
