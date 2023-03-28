// Copyright 2023 Fixstars Corporation
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *example(PyObject *self, PyObject *args) {
  int result = 42;
  return PyLong_FromLong(result);
}

static PyMethodDef ExampleMethods[] = {
    {"example", example, METH_VARARGS, "Test function."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef examplemodule = {PyModuleDef_HEAD_INIT, "example",
                                           NULL, -1, ExampleMethods};

PyMODINIT_FUNC PyInit_example(void) { return PyModule_Create(&examplemodule); }

int main(int argc, char *argv[]) {
  wchar_t *program = Py_DecodeLocale(argv[0], NULL);
  if (program == NULL) {
    fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
    exit(1);
  }

  if (PyImport_AppendInittab("example", PyInit_example) == -1) {
    fprintf(stderr, "Error: could not extend in-built modules table\n");
    exit(1);
  }

  Py_SetProgramName(program);
  Py_Initialize();
  PyObject *pmodule = PyImport_ImportModule("example");
  if (!pmodule) {
    PyErr_Print();
    fprintf(stderr, "Error: could not import module 'example'\n");
  }

  PyMem_RawFree(program);
  return 0;
}