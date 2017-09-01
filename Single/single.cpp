#include "single.h"

Single *Single::_single = new Single;

Single::Single()
{

}

Single *Single::getSingle()
{
    return _single;
}



