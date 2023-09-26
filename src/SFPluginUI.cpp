#include "DistrhoUI.hpp"
#include "Color.hpp"
#include <cstdio>

START_NAMESPACE_DISTRHO

using DGL_NAMESPACE::Color;
using DGL_NAMESPACE::GraphicsContext;
using DGL_NAMESPACE::Rectangle;

class SFPluginUI : public UI
{
public:
    SFPluginUI() :
        UI(DISTRHO_UI_DEFAULT_WIDTH, DISTRHO_UI_DEFAULT_HEIGHT)
    {}
protected:

    void parameterChanged(uint32_t index, float value) override
    {
        printf("%s index=%d\n, value=%f", __func__, index, value);
        // TODO
        repaint();
    }

    void programLoaded(uint32_t index)
    {
        switch (index)
        {
            // TODO
        }
        printf("%s index=%d\n", __func__, index);
    }

    void onDisplay() override
    {
        // must implement
    }

    bool onMouse(const MouseEvent& ev) override
    {
        // true stops event propagation false otherwise
        return true;
    }

    bool onKeyboard(const KeyboardEvent& ev) override
    {
        printf("%s keycode=%d, key=%c\n", __func__, ev.keycode, static_cast<char>(ev.key));
        // true stops event propagation false otherwise
        return true;
    }

private:
    // TODO
};

UI* createUI()
{
    return new SFPluginUI();
}


END_NAMESPACE_DISTRHO
