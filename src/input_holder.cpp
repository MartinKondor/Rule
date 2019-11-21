#include "input_holder.hpp"


InputHolder::InputHolder()
{
    // Set every key's state to false by default
    for (unsigned int i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
    {
        this->keyState[i] = false;
    }
}
