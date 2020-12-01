#include "addbutton.h"

void AddButton::ItemAdded(bool)
{
    emit iChanged(this);
}
