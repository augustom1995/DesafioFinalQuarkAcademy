#pragma once
#ifndef IVIEW_H
#define IVIEW_H
#include <string>
using namespace std;

class IView
{
public:
	virtual ~IView() = default;
	virtual string parseNum(double x) = 0;
	virtual void showText(const string& text) = 0;
	virtual void showTextWithSection(const string& text) = 0;
	virtual void showTextWithOptions(const string& text) = 0;
};
#endif // !IVIEW_H
