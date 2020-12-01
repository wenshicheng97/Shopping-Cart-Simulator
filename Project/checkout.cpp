#include "checkout.h"

void CheckOut::imClicked(bool)
{
    emit iChanged(this);
}
