#pragma once
#ifndef BUTTON_H
#define BUTTON_H

class Button
{
private:

public:
	Button();
	~Button();

	static const int wordArraySize = 50;
	int wordSize = 0;

	char word[wordArraySize] = "Base";

	void run();

};


#endif // !1
