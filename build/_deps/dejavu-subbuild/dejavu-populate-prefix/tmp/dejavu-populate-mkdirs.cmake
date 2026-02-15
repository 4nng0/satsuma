# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/annagoerth/CLionProjects/satsuma/dejavu")
  file(MAKE_DIRECTORY "/Users/annagoerth/CLionProjects/satsuma/dejavu")
endif()
file(MAKE_DIRECTORY
  "/Users/annagoerth/CLionProjects/satsuma/build/_deps/dejavu-build"
  "/Users/annagoerth/CLionProjects/satsuma/build/_deps/dejavu-subbuild/dejavu-populate-prefix"
  "/Users/annagoerth/CLionProjects/satsuma/build/_deps/dejavu-subbuild/dejavu-populate-prefix/tmp"
  "/Users/annagoerth/CLionProjects/satsuma/build/_deps/dejavu-subbuild/dejavu-populate-prefix/src/dejavu-populate-stamp"
  "/Users/annagoerth/CLionProjects/satsuma/build/_deps/dejavu-subbuild/dejavu-populate-prefix/src"
  "/Users/annagoerth/CLionProjects/satsuma/build/_deps/dejavu-subbuild/dejavu-populate-prefix/src/dejavu-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/annagoerth/CLionProjects/satsuma/build/_deps/dejavu-subbuild/dejavu-populate-prefix/src/dejavu-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/annagoerth/CLionProjects/satsuma/build/_deps/dejavu-subbuild/dejavu-populate-prefix/src/dejavu-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
