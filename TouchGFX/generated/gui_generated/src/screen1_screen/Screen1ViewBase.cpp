/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase()
{
    __background.setPosition(0, 0, 480, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_DARK_THEME_IMAGES_BACKGROUNDS_480X480_CARBON_ID));
    add(image1);

    txtTemp.setPosition(140, 215, 200, 50);
    txtTemp.setColor(touchgfx::Color::getColorFromRGB(56, 240, 10));
    txtTemp.setLinespacing(0);
    Unicode::snprintf(txtTempBuffer, TXTTEMP_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_QF8C).getText());
    txtTemp.setWildcard(txtTempBuffer);
    txtTemp.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0FBR));
    add(txtTemp);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}
