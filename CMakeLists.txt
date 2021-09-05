cmake_minimum_required(VERSION 3.5)
project(fverb)

add_subdirectory(dpf)

if(WIN32)
  add_definitions("-D_USE_MATH_DEFINES" "-DNOMINMAX")
endif()

dpf_add_plugin(fverb
  TARGETS lv2 vst2
  FILES_DSP
    "plugins/fverb/PluginFverb.cpp"
    "plugins/fverb/dsp/Fverb.cpp")

target_include_directories(fverb
  PUBLIC
    "plugins/fverb"
    "thirdparty/blink")

if(MSVC)
  target_compile_options(fverb PRIVATE "/fp:fast")
else()
  target_compile_options(fverb PRIVATE "-ffast-math")
endif()
