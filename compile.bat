git diff --name-only > diff.txt
compile.exe
@echo off
FOR /F "tokens=*" %%G IN ('dir /b /A-D src') do (
    if not exist %%~nG.o (
        if %%~xG EQU .c (
            echo gcc -c ./src/%%~nxG -Iincludes
            gcc -c ./src/%%~nxG -Iincludes
        ) else (
            echo g++ -c ./src/%%~nxG -Iincludes
            g++ -c ./src/%%~nxG -Iincludes
        )
    )
)

    
