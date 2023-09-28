file(GLOB_RECURSE sources
    "*.c"
    "*.cpp"
    "*.ui"
    "*.qrc"
    "*.h"
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MyQtProject
        MANUAL_FINALIZATION
        ${sources}
        ${header_files}
    )
else()
    add_executable(MyQtProject
        ${sources}
    )
endif()

# Link to math library if compiler is gnu
if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
    target_link_libraries(MyQtProject PRIVATE m)
endif()

target_link_libraries(MyQtProject PRIVATE
    opencv_face 
    opencv_core 
    opencv_imgproc 
    opencv_highgui 
    opencv_objdetect 
    opencv_imgproc
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
    Qt${QT_VERSION_MAJOR}::SerialPort
    ${Boost_LIBRARIES}
    )

set_target_properties(MyQtProject PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MyQtProject)
endif()
