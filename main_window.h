#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "windows.h"

// Main Window class
class main_window : public windows
{
public:
    virtual void draw() override;
    virtual void update() override;
    virtual all_windows get_window_id() override;
    virtual void on_btn_pressed(int id) override;
    virtual void on_btn_holded(int id) override;

private:
    int time = 0;
    bool state = false;
};

// create a single instance
extern main_window main_window_ins;

#endif