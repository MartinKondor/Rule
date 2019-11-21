#ifndef INPUT_HOLDER_HPP_INCLUDED
#define INPUT_HOLDER_HPP_INCLUDED


#include <irrlicht.h>

class InputHolder
{
public:
    irr::SEvent::SMouseInput mouseInput;
    bool keyState[irr::KEY_KEY_CODES_COUNT];  // Keys status

    InputHolder();
};

#endif // INPUT_HOLDER_HPP_INCLUDED
