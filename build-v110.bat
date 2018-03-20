@echo off

echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
echo  Build Bitnote.
echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
if "%~1"=="--skipboost"  (
    echo  NOTE: skipping boost download ^& build.
    goto SKIP_BOOST
)

set BOOST_VER_DS=1.58.0
set BOOST_VER_US=%BOOST_VER_DS:.=_%

echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
echo  Download ^& unzip boost %BOOST_VER_DS% to %BOOST_VER_US%. This may take awhile.
echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
pushd .
cd external
powershell -ExecutionPolicy ByPass -File get-boost.ps1 %BOOST_VER_DS%
popd

echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
echo  Bootstrap boost build.
echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
pushd .
cd external/boost_%BOOST_VER_US%
call bootstrap.bat
popd

echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
echo  Set up vs2012 env vars.
echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x64

echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
echo  Build boost.
echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
pushd .
cd external/boost_%BOOST_VER_US%
.\b2 ^
   --build-type=minimal^
   --build-dir=build^
   --stagedir=stage^
   --toolset=msvc-11.0^
   variant=release^
   architecture=x86^
   address-model=64^
   link=static^
   threading=multi^
   runtime-link=static^
   --with-system^
   --with-filesystem^
   --with-thread^
   --with-date_time^
   --with-chrono^
   --with-regex^
   --with-serialization^
   --with-program_options^
   -j 8^
   -q
popd

:SKIP_BOOST
echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
echo  Call Cmake. This can fail if your Cmake is not up to date.
echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
pushd .
if not exist build md build
cd build
cmake .. -G "Visual Studio 11 2012 Win64"^
 -DBOOST_ROOT=external\boost_%BOOST_VER_US%^
 -DBOOST_INCLUDEDIR=external\boost_%BOOST_VER_US%^
 -DBOOST_LIBRARYDIR=external\boost_%BOOST_VER_US%\stage\lib
cmake --build . --target ALL_BUILD --config Release
popd

echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
echo  Done. NOTE: if you have errors about version.h not being found, just try
echo  running the build again (seems like there is some obscure Cmake issue that
echo  occurs on the initial build). To skip download ^& build of boost in the
echo  future, pass '--skipboost' as the first argument to this script.
echo :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

pause
