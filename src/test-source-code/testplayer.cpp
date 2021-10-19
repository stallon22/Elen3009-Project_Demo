#include "Player.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

TEST_CASE("Testing player movement")
{
    float delX = 10.f;
    float delY = -20.f;
Player ptest;

ptest.move_player(delX,delY);

}
