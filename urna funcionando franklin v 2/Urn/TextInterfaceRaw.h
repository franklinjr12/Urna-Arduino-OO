#ifndef TEXTINTERFACERAW_H
#define TEXTINTERFACERAW_H

class TextInterfaceRaw
{

private:
    LiquidCrystal* lcd;

public:

    void showText(char* text);
    void clearScreen();
    TextInterfaceRaw(LiquidCrystal* lcd){ this->lcd = lcd; lcd->begin(16,2);}
};

void TextInterfaceRaw::clearScreen()
{
  this->lcd->clear();
  this->lcd->setCursor(0,0);
}

void TextInterfaceRaw::showText(char *text)
{
    //error chech
    if(lcd == 0 || text == 0) return;    //null pointer
    //================================================================================================================

    clearScreen();

    int textSize = 0;
    int textControl = 0;
    while(text[textSize] != '\0') textSize++;

    //check if messege fits in two lines
    if(textSize <= 32)
        //will print text normally
        for(int i = 0; i < textSize; i++)
        {
            if(i > 15)
            {
                lcd->setCursor(i-16, 1);
                lcd->print(text[i]);
            }
            else
            {
                lcd->setCursor(i, 0);
                lcd->print(text[i]);
            }
        }//end of printing text lesser than 17 letters
    //================================================================================================================

    else
    {//case the text doesnt fit in the screen
        for(int i = 0; i < 1+(textSize / 32); i++)  //amount of data that fits in the screen
        {
            for(int j = 0; j < textSize - (i*32) ; j++)
            {
                if(j > 15)
                {
                    lcd->setCursor(j-16, 1);
                    lcd->print(text[textControl++]);
                }
                else
                {
                    lcd->setCursor(j, 0);
                    lcd->print(text[textControl++]);
                }
            }
            delay(3000);
            lcd->clear();
        }
    }//end of printing text greater than 17 letters
    //================================================================================================================
}
#endif // TEXTINTERFACERAW_H
