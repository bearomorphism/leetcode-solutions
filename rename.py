import os

for f in os.listdir('.'):
  if f.isdigit() and os.path.isdir(f):
    try:
      os.rename(f"{f}/main.cpp", f"{f}.cpp")
    except:
      os.removedirs(f)
