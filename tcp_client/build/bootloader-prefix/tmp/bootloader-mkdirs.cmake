# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/esp/v5.1.3/esp-idf/components/bootloader/subproject"
  "D:/CodeField_C/tcp_client/build/bootloader"
  "D:/CodeField_C/tcp_client/build/bootloader-prefix"
  "D:/CodeField_C/tcp_client/build/bootloader-prefix/tmp"
  "D:/CodeField_C/tcp_client/build/bootloader-prefix/src/bootloader-stamp"
  "D:/CodeField_C/tcp_client/build/bootloader-prefix/src"
  "D:/CodeField_C/tcp_client/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/CodeField_C/tcp_client/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/CodeField_C/tcp_client/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
