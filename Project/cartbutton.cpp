#include "cartbutton.h"

void CartButton::imClicked(bool)
{
    emit iChanged(this);
}
