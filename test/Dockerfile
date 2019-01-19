FROM cpython-minimal

RUN New-Item -ItemType directory -Path C:\hello

WORKDIR C:\\hello

COPY hello.c .
COPY setup.py .

RUN python setup.py install
RUN python -c "'import hello; hello.say(''Here is some stuff...'')'"
