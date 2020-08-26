#pragma once

#include <stdint.h>
#include <stddef.h>
#include "consts.h"

struct SaveEntry
{
	static constexpr size_t nameSize = NAME_LENGTH_PLUS_TERM;
	static constexpr size_t nameCount = (nameSize - 1);

	uint16_t score;
	char name[nameSize];
};