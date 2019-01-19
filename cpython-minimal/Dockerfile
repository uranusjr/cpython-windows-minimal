FROM microsoft/dotnet-framework:4.7.1

SHELL ["powershell.exe", "-Command", "$ErrorActionPreference = 'Stop'; $ProgressPreference = 'SilentlyContinue';"]

CMD ["powershell.exe", "-NoLogo", "-ExecutionPolicy", "Bypass"]

ADD 'https://www.python.org/ftp/python/3.7.1/python-3.7.1-amd64.exe' .
RUN Start-Process .\python-3.7.1-amd64.exe -Wait -ArgumentList @( \
    '/quiet', \
    'InstallAllUsers=1', \
    'TargetDir=C:\\Python', \
    'PrependPath=1', \
    'Shortcuts=0', \
    'Include_doc=0', \
    'Include_pip=0', \
    'Include_test=0') \
  ; $env:PATH = [Environment]::GetEnvironmentVariable(\
    'PATH', [EnvironmentVariableTarget]::Machine) \
  ; Remove-Item .\python-3.7.1-amd64.exe \
  ;

# ADD 'https://bootstrap.pypa.io/get-pip.py' get-pip.py
# RUN python get-pip.py --disable-pip-version-check --no-cache-dir \
#   ; Remove-Item .\get-pip.py

ADD 'https://aka.ms/vs/15/release/vs_buildtools.exe' vs_buildtools.exe
RUN $ErrorActionPreference = 'Stop' \
  ; $VerbosePreference = 'Continue' \
  ; $p = Start-Process -Wait -PassThru \
    -FilePath C:\vs_buildtools.exe \
    -ArgumentList @( \
    '--add', 'microsoft.visualstudio.component.vc.corebuildtools', \
		'--add', 'microsoft.visualstudio.component.vc.tools.x86.x64', \
		'--add', 'microsoft.visualstudio.component.windows10sdk.16299.desktop', \
    '--quiet', '--nocache', '--wait', \
    '--installPath', 'C:\\BuildTools') \
  ; if ($ret = $p.ExitCode) { throw ('Install failed with 0x{0:x}' -f $ret) }
