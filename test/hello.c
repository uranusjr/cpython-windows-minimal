#include <stdio.h>
#include <Python.h>

static PyObject *hello_say(PyObject *self, PyObject *args)
{
    const char *msg;
    if (!PyArg_ParseTuple(args, "s", &msg))
        return NULL;
    fprintf(stdout, "Hello! %s\n", msg);
    return Py_None;
}

static PyMethodDef HelloMethods[] = {
    {"say", hello_say, METH_VARARGS, "Say stuff."},
    {NULL, NULL, 0, NULL},
};

static struct PyModuleDef hellomodule = {
    PyModuleDef_HEAD_INIT,
    "hello",
    NULL,
    -1,
    HelloMethods,
};

PyMODINIT_FUNC
PyInit_hello(void)
{
    PyObject *m = PyModule_Create(&hellomodule);
    if (!m)
        return NULL;
    return m;
}
