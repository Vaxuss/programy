#ifndef THING_H
#define THING_H


class Thing
{
public:
    void set(int num, char c);
    void increment();
    void show();
    void display_Num();
    void display_Char();
private:
    int m_Number;
    char m_Character;
};

#endif // THING_H
