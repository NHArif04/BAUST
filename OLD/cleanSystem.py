import os
import subprocess
recPath = 'C:\\Windows\\Temp'
ls = []
if os.path.exists(recPath):
    for i in os.listdir(recPath):
        ls.append(os.path.join(recPath, i))
else:
    print('Please provide valid path!')

paths = ' '.join(ls)
pObj = subprocess.Popen('rmdir C:\\Windows\\Temp\\*.* /s /q *.*'+paths, shell=True, stdout = subprocess.PIPE, stderr= subprocess.PIPE)
rTup = pObj.communicate()
rCod = pObj.returncode
if rCod == 0:
    print('Success: Cleaned Windows Temp Folder')
else:
    print('Fail: Unable to Clean Windows Temp Folder')