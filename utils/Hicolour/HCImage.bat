rem Highcoloyr images for GBC

rem Rename "NAME" variable to your image name: name.til name.map... 
rem these files will be deleted if there is no error

rem Rename "BANK" variable to your bank

set "NAME=test"
set "BANK=2"

rem ///////////////////////////////////
echo %NAME%
echo %BANK%
rem Convert the image data to arrays
bin2h %NAME%.til til.h
bin2h %NAME%.atr atr.h
bin2h %NAME%.map map.h
bin2h %NAME%.pal pal.h


@echo off
rem Write the file in asm format for game boy

rem TILES & HEADERS
call jrepl "^//file" ";;" /f til.h /o -
call jrepl "size_t" ";headers\n.area _CODE_%BANK%\n.dw %NAME%Til\n.dw %NAME%Atr\n.dw %NAME%Map\n.dw %NAME%Pal\n;data" /X /f til.h /o -
call jrepl "unsigned char" "%NAME%Til:: ;" /f til.h /o -
call jrepl "{" " " /f til.h /o -
call jrepl "};" " " /f til.h /o -
call jrepl "	0x" ".db 0x" /f til.h /o -
call jrepl ",$" " " /f til.h /o -
rem ATR
call jrepl "^//file" ";;" /f atr.h /o -
call jrepl "size_t" ";;" /f atr.h /o -
call jrepl "unsigned char" "%NAME%Atr:: ;" /f atr.h /o -
call jrepl "{" " " /f atr.h /o -
call jrepl "};" " " /f atr.h /o -
call jrepl "	0x" ".db 0x" /f atr.h /o -
call jrepl ",$" " " /f atr.h /o -
rem MAP
call jrepl "^//file" ";;" /f map.h /o -
call jrepl "size_t" ";;" /f map.h /o -
call jrepl "unsigned char" "%NAME%Map:: ;" /f map.h /o -
call jrepl "{" " " /f map.h /o -
call jrepl "};" " " /f map.h /o -
call jrepl "	0x" ".db 0x" /f map.h /o -
call jrepl ",$" " " /f map.h /o -
rem PALETTES
call jrepl "^//file" ";;" /f pal.h /o -
call jrepl "size_t" ";;" /f pal.h /o -
call jrepl "unsigned char" "%NAME%Pal:: ;" /f pal.h /o -
call jrepl "{" " " /f pal.h /o -
call jrepl "};" " " /f pal.h /o -
call jrepl "	0x" ".db 0x" /f pal.h /o -
call jrepl ",$" " " /f pal.h /o -

rem Join the files
copy til.h+atr.h+map.h+pal.h %NAME%.b%BANK%.s
del *.h	*.til *.atr *.map *.pal

pause	