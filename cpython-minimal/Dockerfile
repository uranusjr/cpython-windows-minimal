FROM microsoft/dotnet-framework:4.7.1

SHELL ["powershell.exe", "-NoLogo", "-ExecutionPolicy", "Bypass", "-Command"]

CMD ["powershell.exe", "-NoLogo", "-ExecutionPolicy", "Bypass"]

ENV PYTHON_VERSION 3.7.1

ENV PYTHON_INSTALLER_NAME "python-${PYTHON_VERSION}-amd64.exe"
ENV PYTHON_INSTALLER_PRE "https://www.python.org/ftp/python/${PYTHON_VERSION}"

ADD "${PYTHON_INSTALLER_PRE}/${PYTHON_INSTALLER_NAME}" .

RUN $ErrorActionPreference = 'Stop' \
  ; $ProgressPreference = 'SilentlyContinue' \
  ; $VerbosePreference = 'Continue' \
  ; $p = Start-Process -Wait -PassThru \
    -FilePath $Env:PYTHON_INSTALLER_NAME \
    -ArgumentList @( \
    '/quiet', \
    'InstallAllUsers=1', \
    'TargetDir=C:\\Python', \
    'PrependPath=1', \
    'Shortcuts=0', \
    'Include_doc=0', \
    'Include_pip=0', \
    'Include_test=0') \
  ; $Env:PATH = [Environment]::GetEnvironmentVariable(\
    'PATH', [EnvironmentVariableTarget]::Machine) \
  ; Remove-Item $Env:PYTHON_INSTALLER_NAME \
  ;

# ADD 'https://bootstrap.pypa.io/get-pip.py' get-pip.py
# RUN python get-pip.py --disable-pip-version-check --no-cache-dir \
#   ; Remove-Item get-pip.py

ADD 'https://aka.ms/vs/15/release/vs_buildtools.exe' .

RUN $ErrorActionPreference = 'Stop' \
  ; $VerbosePreference = 'Continue' \
  ; $p = Start-Process -Wait -PassThru \
    -FilePath vs_buildtools.exe \
    -ArgumentList @( \
    '--add', 'microsoft.visualstudio.component.vc.corebuildtools', \
    '--add', 'microsoft.visualstudio.component.vc.tools.x86.x64', \
    '--add', 'microsoft.visualstudio.component.windows10sdk.16299.desktop', \
    '--quiet', '--nocache', '--wait', \
    '--installPath', 'C:\\BuildTools') \
  ; if ($ret = $p.ExitCode) { throw ('Install failed with 0x{0:x}' -f $ret) }
RUN Remove-Item vs_buildtools.exe 
