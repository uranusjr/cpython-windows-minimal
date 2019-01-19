# Based on the MSDN blog: http://bit.ly/docker-vs2017

# 3.7.2 does not work due to bpo-35699. https://bugs.python.org/issue35699
FROM python:3.7.1-windowsservercore-1709

SHELL ["powershell.exe", "-NoLogo", "-ExecutionPolicy", "Bypass", "-Command"]

CMD ["powershell.exe", "-NoLogo", "-ExecutionPolicy", "Bypass"]

ENV VS_VERSION 15
ENV VS_INSTALLER_NAME "vs_buildtools.exe"

# Install Visual Studio Build Tools.

ADD "https://aka.ms/vs/${VS_VERSION}/release/${VS_INSTALLER_NAME}" .

RUN $ErrorActionPreference = 'Stop' \
  ; $VerbosePreference = 'Continue' \
  ; $p = Start-Process -Wait -PassThru \
    -FilePath $Env:VS_INSTALLER_NAME \
    -ArgumentList @( \
    '--add', 'microsoft.visualstudio.component.vc.corebuildtools', \
    '--add', 'microsoft.visualstudio.component.vc.tools.x86.x64', \
    '--add', 'microsoft.visualstudio.component.windows10sdk.16299.desktop', \
    '--quiet', '--nocache', '--wait', \
    '--installPath', 'C:\\BuildTools') \
  ; if ($ret = $p.ExitCode) { throw ('Install failed with 0x{0:x}' -f $ret) }

RUN Remove-Item $Env:VS_INSTALLER_NAME
