# Install script for directory: /home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX/headers" TYPE FILE FILES "/home/z/桌面/i18n_xlsx/build/lib/OpenXLSX/OpenXLSX/OpenXLSX-Exports.hpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX/headers" TYPE FILE FILES
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLCell.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLCellIterator.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLCellRange.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLCellReference.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLCellValue.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLColor.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLColumn.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLCommandQuery.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLConstants.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLContentTypes.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLDateTime.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLDocument.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLException.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLFormula.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLIterator.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLProperties.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLRelationships.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLRow.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLRowData.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLSharedStrings.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLSheet.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLWorkbook.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLXmlData.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLXmlFile.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLXmlParser.hpp"
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/headers/XLZipArchive.hpp"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX" TYPE FILE FILES "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/OpenXLSX.hpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/z/桌面/i18n_xlsx/build/output/libOpenXLSX.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES
    "/home/z/桌面/i18n_xlsx/lib/OpenXLSX/OpenXLSX/OpenXLSXConfig.cmake"
    "/home/z/桌面/i18n_xlsx/build/lib/OpenXLSX/OpenXLSX/OpenXLSX/OpenXLSXConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake"
         "/home/z/桌面/i18n_xlsx/build/lib/OpenXLSX/OpenXLSX/CMakeFiles/Export/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES "/home/z/桌面/i18n_xlsx/build/lib/OpenXLSX/OpenXLSX/CMakeFiles/Export/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES "/home/z/桌面/i18n_xlsx/build/lib/OpenXLSX/OpenXLSX/CMakeFiles/Export/lib/cmake/OpenXLSX/OpenXLSXTargets-noconfig.cmake")
  endif()
endif()

