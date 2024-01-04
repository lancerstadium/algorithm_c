add_rules("mode.debug", "mode.release")

set_languages("c11", "c++11")

target("c2_1")
    set_kind("binary")
    add_files("src/c2_1.c")

target("c2_2")
    set_kind("binary")
    add_files("src/c2_2.c")

target("c3_1")
    set_kind("binary")
    add_files("src/c3_1.c")

target("c3_2")
    set_kind("binary")
    add_files("src/c3_2.c")

target("c3_3")
    set_kind("binary")
    add_files("src/c3_3.c")

target("c4_1")
    set_kind("binary")
    add_files("src/c4_1.c")

target("c4_2")
    set_kind("binary")
    add_files("src/c4_2.c")

target("c4_3")
    set_kind("binary")
    add_files("src/c4_3.c")

target("c5_1")
    set_kind("binary")
    add_files("src/c5_1.c")

target("c5_2")
    set_kind("binary")
    add_files("src/c5_2.c")

target("c5_3")
    set_kind("binary")
    add_files("src/c5_3.c")

target("c6_1")
    set_kind("binary")
    add_files("src/c6_1.c")

target("c6_2")
    set_kind("binary")
    add_files("src/c6_2.c")

target("c6_3")
    set_kind("binary")
    add_files("src/c6_3.c")

target("c7_1")
    set_kind("binary")
    add_files("src/c7_1.c")

target("c7_2")
    set_kind("binary")
    add_files("src/c7_2.c")

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

