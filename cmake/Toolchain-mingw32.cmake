# the name of the target operating system
set(CMAKE_SYSTEM_NAME Windows)

#remove the runtime dependency for libgcc_s_sjlj-1.dll
set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-libgcc")

# Which compilers to use for C and C++, and location of target
# environment.
if(EXISTS /usr/i686-w64-mingw32)
# First look in standard location as used by Debian/Ubuntu/etc.
set(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)
set(CMAKE_RC_COMPILER i686-w64-mingw32-windres)
set(CMAKE_AR:FILEPATH /usr/bin/i686-w64-mingw32-ar)
set(CMAKE_FIND_ROOT_PATH /usr/i686-w64-mingw32)
elseif(EXISTS /usr/i586-mingw32msvc)
# First look in standard location as used by Debian/Ubuntu/etc.
set(CMAKE_C_COMPILER i586-mingw32msvc-gcc)
set(CMAKE_CXX_COMPILER i586-mingw32msvc-g++)
set(CMAKE_RC_COMPILER i586-mingw32msvc-windres)
set(CMAKE_FIND_ROOT_PATH /usr/i586-mingw32msvc)
elseif(EXISTS /opt/mingw)
# You can get a MinGW environment using the script at <http://mxe.cc>.
# It downloads and builds MinGW and most of the dependencies for you.
# You can use the toolchain file generated by MXE called `mxe-conf.cmake'
# or you can use this file by adjusting the above and following paths.
set(CMAKE_C_COMPILER /opt/mingw/usr/bin/i686-pc-mingw32-gcc)
set(CMAKE_CXX_COMPILER /opt/mingw/usr/bin/i686-pc-mingw32-g++)
set(CMAKE_RC_COMPILER /opt/mingw/usr/bin/i686-pc-mingw32-windres)
set(CMAKE_FIND_ROOT_PATH /opt/mingw/usr/i686-pc-mingw32)
else()
# Else fill in local path which the user will likely adjust.
# This is the location assumed by <http://www.libsdl.org/extras/win32/cross/>
set(CMAKE_C_COMPILER /usr/local/cross-tools/bin/i386-mingw32-gcc)
set(CMAKE_CXX_COMPILER /usr/local/cross-tools/bin/i386-mingw32-g++)
set(CMAKE_RC_COMPILER /usr/local/cross-tools/bin/i386-mingw32-windres)
set(CMAKE_FIND_ROOT_PATH /usr/local/cross-tools)
endif() 

# Adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
# Tell pkg-config not to look at the target environment's .pc files.
# Setting PKG_CONFIG_LIBDIR sets the default search directory, but we have to
# set PKG_CONFIG_PATH as well to prevent pkg-config falling back to the host's
# path.
set(ENV{PKG_CONFIG_LIBDIR} ${CMAKE_FIND_ROOT_PATH}/lib/pkgconfig)
set(ENV{PKG_CONFIG_PATH} ${CMAKE_FIND_ROOT_PATH}/lib/pkgconfig)
set(ENV{MINGDIR} ${CMAKE_FIND_ROOT_PATH}) 
