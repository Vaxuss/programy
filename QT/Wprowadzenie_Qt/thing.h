#ifndef THING_H
#define THING_H

#include <Qstring>

class Thing
{
public:
    Thing(int a, int b);
    ~Thing();
    void display() const;
    static void showCount();
private:
    int m_First, m_Second;
    static int s_Count;

};

#endif // THING_H
