
INCLUDE_DIRECTORIES(mcommon)

list(APPEND COMMON_SOURCES

mcommon/ui/uimanager.cpp
mcommon/ui/uimanager.h

mcommon/animation/timer.cpp
mcommon/animation/timer.h

mcommon/file/fileutils.cpp
mcommon/file/fileutils.h
mcommon/file/media_manager.cpp
mcommon/file/media_manager.h

mcommon/math/mathutils.h
mcommon/math/mathutils.cpp

mcommon/string/stringutils.cpp
mcommon/string/stringutils.h

mcommon/string/hashstring.h
mcommon/string/hashstring.cpp

mcommon/string/murmur_hash.cpp
mcommon/string/murmur_hash.h

mcommon/mcommon.h
mcommon/mcommon.cpp

)
set(MCOMMON_ROOT ${CMAKE_CURRENT_LIST_DIR} CACHE STRING "" FORCE)
SOURCE_GROUP ("mcommon" REGULAR_EXPRESSION "(mcommon)+.*")
