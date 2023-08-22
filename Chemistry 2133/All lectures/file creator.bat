@echo off

for /L %%i in (5,1,38) do (
    echo ^<!DOCTYPE html^> > lecture-%%i.html
    echo ^<html lang="en"^> >> lecture-%%i.html
    echo ^<head^> >> lecture-%%i.html
    echo     ^<meta charset="UTF-8"^> >> lecture-%%i.html
    echo     ^<meta name="viewport" content="width=device-width, initial-scale=1.0"^> >> lecture-%%i.html
    echo     ^<title^>Structure of Atom^</title^> >> lecture-%%i.html
    echo     ^<link rel="stylesheet" href="styles.css"^> >> lecture-%%i.html
    echo ^</head^> >> lecture-%%i.html
    echo ^<body^> >> lecture-%%i.html
    echo ^<span class="date"^>Date: %%i July, 2023^</span^> >> lecture-%%i.html
    echo ^<span class="lecture-number"^>Lecture - %%i^</span^> >> lecture-%%i.html
    echo ^<h2^>^<mark^>Structure of Atom^</mark^>^</h2^> >> lecture-%%i.html
    echo ^</body^> >> lecture-%%i.html
    echo ^</html^> >> lecture-%%i.html
)

echo Done!
