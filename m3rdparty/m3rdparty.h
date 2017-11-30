#pragma once

// Don't let windows include the silly min/max macro
#define NOMINMAX

#include <cstdlib>

#define mynew new

#ifdef _DEBUG
#if defined(_MSC_VER)
// Memory leak/corruption detection for Windows
#define _CRTDBG_MAP_ALLOC
#undef mynew
#define mynew new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#include <crtdbg.h>
#endif // MSVC
#endif // _DEBUG

// Standard library, used all the time.
#include <cstdint>  // uint64_t, etc.
#include <cctype>
#include <string>
#include <chrono>     // Timing
#include <algorithm>  // Various useful things
#include <memory>     // shared_ptr
#include <sstream>

// Containers, used all the time.
#include <vector>
#include <map>

// IO
#include <iostream>
#include <fstream>

// GLM
#define GLM_ENABLE_EXPERIMENTAL
#define GLM_LANG_STL11_FORCED
#define GLM_FORCE_LEFT_HANDED
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "glm/glm/gtx/rotate_vector.hpp"
#include "glm/glm/gtc/quaternion.hpp"
#include "glm/glm/gtc/random.hpp"
#include "glm/glm/gtx/string_cast.hpp"

// For logging events to file
#include <easylogging/src/easylogging++.h>

#include "config_shared.h"

#include <easylogging/src/easylogging++.h>
