#include <bits/stdc++.h>


// =========================================================
// COMPONENT
// =========================================================

class TextView {
public:

	virtual void render() = 0;
	virtual ~TextView() = default;
};

// =========================================================
// Concrete Component (BASIC / DEFAULT / RAW / VANILLA)
// =========================================================

class PlainTextView : public TextView {
private:

	std::string text;
	
public:

	PlainTextView(const std::string &text) : text(text) {} 

	void render() {
		std::cout << text;
	}
};

// =========================================================
// ABSTRACT DECORATOR
// =========================================================

class TextDecorator : public TextView {
protected:

	TextView *inner;
	
public:

	TextDecorator(TextView *inner) : inner(inner) {}

};

// =========================================================
// CONCRETE DECORATORS
// =========================================================

class BoldTextDecorator : public TextDecorator{
public:

	BoldTextDecorator(TextView *inner) : TextDecorator(inner) {}
	
	void render() {
		std::cout << "<b>";
		inner->render();
		std::cout << "</b>";
	}
};

class ItalicTextDecorator : public TextDecorator{
public:

	ItalicTextDecorator(TextView *inner) : TextDecorator(inner) {}
	
	void render() {
		std::cout << "<i>";
		inner->render();
		std::cout << "</i>";
	}
};

class UnderlineTextDecorator : public TextDecorator{
public:

	UnderlineTextDecorator(TextView *inner) : TextDecorator(inner) {}
	
	void render() {
		std::cout << "<u>";
		inner->render();
		std::cout << "</u>";
	}
};


// =========================================================
// CLIENT CODE
// =========================================================

int main() {
	
	std::string raw_text;
	std::cin >> raw_text;
	
	TextView *tv = new PlainTextView("Hello World!");
	TextView *uibt = new UnderlineTextDecorator(new ItalicTextDecorator(new BoldTextDecorator(tv)));
	
	uibt->render();
	
	return 0;
}