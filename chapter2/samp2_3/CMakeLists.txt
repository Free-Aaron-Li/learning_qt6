cmake_minimum_required(VERSION 3.16) # 需要的CMake最低版本

project(samp2_3 VERSION 0.1 LANGUAGES CXX) # 项目版本0.1，编程语言为C++

set(CMAKE_AUTOUIC ON) # UIC能被自动执行
set(CMAKE_AUTOMOC ON) # MOC能被自动执行
set(CMAKE_AUTORCC ON) # RCC 能被自动执行

set(CMAKE_CXX_STANDARD 17) # 编译器需要满足的C++语言标准，设置为C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 要求编译器需要满足C++标准

# 上述二者区别：前者设定目标C++标准版本，而后者确保编译环境在不支持该标准情况下构建失败，
# 避免在不兼容的环境下编译。

# 尝试查找Qt6 Qt5，REQUIRED表示如果找不到二者中任意一个，CMake配置阶段失败。
# COMPONENTS Widgets表明至少要有Widgets模块
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)

# 前者的动态写法，灵活确定的Qt版本
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# 在顶层项目下以“bin/二级目录”方式生成可执行文件
get_filename_component(SECONDARY_DIR "${PROJECT_SOURCE_DIR}/.." ABSOLUTE)
get_filename_component(SECONDARY_DIR_NAME "${SECONDARY_DIR}" NAME)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../bin/${SECONDARY_DIR_NAME})

# 禁止输出qDebug()调试信息
add_definitions(-DQT_NO_DEBUG_OUTPUT)

# 设置项目源文件列表
set(PROJECT_SOURCES
        main.cpp
        dialog.cpp
        dialog.h
        dialog.ui
)


if (${QT_VERSION_MAJOR} GREATER_EQUAL 6) # 如果是Qt 6 及以上版本
    qt_add_executable(samp2_3            # 创建可执行文件 samp2_3
            MANUAL_FINALIZATION          # 手动结束创建目标的过程
            ${PROJECT_SOURCES}           # 来源于 PROJECT_SOURCES
    )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET samp2_3 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else () # 决定项目是被编译为一个Android共享库还是一个普通的可执行文件
    if (ANDROID) # 当前构建目标是否为Android平台
        add_library(samp2_3 SHARED # 创建名为samp2_3的共享库（通常指的是.so动态库）
                ${PROJECT_SOURCES}
        )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else ()
        add_executable(samp2_3
                ${PROJECT_SOURCES}
        )
    endif ()
endif ()

# 在生成目标samp2_3时，需要利用前面的find_package()导入的Widgets模块
target_link_libraries(samp2_3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if (${QT_VERSION} VERSION_LESS 6.1.0) # 针对macOS平台设置
    # 当版本小于6.1.0时，设置宏BUNDLE_ID_OPTION，用于指定macOS应用程序包的GUI标识符（mocOS应用签名和识别的关键部分）
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.samp2_3)
endif ()
set_target_properties(samp2_3 PROPERTIES # 设置目标属性
        ${BUNDLE_ID_OPTION} # 基于前面的条件检查，可能设置GUI标识符
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION} # 设置macOS bundle版本信息
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR} # 设置macOS bundle的简短版本字符串，格式为：主版本号.此版本号
        MACOSX_BUNDLE TRUE # 明确指定samp2_3作为macOS的bundle应用
        WIN32_EXECUTABLE TRUE # 对于Windows平台，标记samp2_3为可执行文件
)

include(GNUInstallDirs) # 映入CMake的标准路径变量
install(TARGETS samp2_3 # 定义samp2_3的安装规则
        BUNDLE DESTINATION . # 如果为bundle，则安装在当前目录下
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # 如果是库，则安装在指定目录下
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # 如果是可执行文件，则安装在指定目录下
)

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(samp2_3) # 最后生成可执行文件 samp2_3
endif ()
