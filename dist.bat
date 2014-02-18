md .\DG_ZThreadLib
md .\DG_ZThreadLib\Win32
md .\DG_ZThreadLib\Win32\Debug
md .\DG_ZThreadLib\Win32\Release
md .\DG_ZThreadLib\x64
md .\DG_ZThreadLib\x64\Debug
md .\DG_ZThreadLib\x64\Release
md .\DG_ZThreadLib\include
md .\DG_ZThreadLib\include\zthread

copy .\VS2010\Win32\Debug\GD_ZThreadLib.lib .\DG_ZThreadLib\Win32\Debug
copy .\VS2010\Win32\Release\GD_ZThreadLib.lib .\DG_ZThreadLib\Win32\Release

copy .\VS2010\x64\Debug\GD_ZThreadLib.lib .\DG_ZThreadLib\x64\Debug
copy .\VS2010\x64\Release\GD_ZThreadLib.lib .\DG_ZThreadLib\x64\Release

copy .\include\zthread\*.h .\DG_ZThreadLib\include\zthread