// "use-and-throw" relationship
// weakest form of relationship

#include <bits/stdc++.h>
using namespace std;

class Document {
private:
    string content;
public:
    Document(const string& content) : content(content) {}

    string getContent() const {
        return content;
    }
};

class Printer {
public:
    void print(const Document& document) const {
        cout << "Printing: " << document.getContent() << endl;
    }
};

int main() {
    Document doc("Hello, World!");
    Printer printer;

    printer.print(doc);

    // After print() returns, the printer has no reference to the document.
    // Both objects have completely independent lifecycles.

    return 0;
}
