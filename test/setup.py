from distutils.core import setup, Extension
from distutils.log import set_threshold

set_threshold(0)

setup(
    name="hello",
    version="1.0",
    description="Hello!",
    ext_modules=[Extension("hello", sources=["hello.c"])],
)
