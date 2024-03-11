#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::update(float temp)
{
	Unicode::snprintfFloat(txtTempBuffer, TXTTEMP_SIZE, "%.2f", temp);
	txtTemp.invalidate();
}
