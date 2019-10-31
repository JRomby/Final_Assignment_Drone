#include <Position.h>

Position::Position( int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
Position::Position()
{
    this->x = -1;
    this->y = -1;
    this->z = -1;
}