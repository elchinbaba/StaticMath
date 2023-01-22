#include <Python.h>

/*
 * Implements an example function.
 */
PyDoc_STRVAR(MathPythonEM_example_doc, "example(obj, number)\
\
Example function");

PyObject *MathPythonEM_example(PyObject *self, PyObject *args, PyObject *kwargs) {
    /* Shared references that do not need Py_DECREF before returning. */
    PyObject *obj = NULL;
    int number = 0;

    /* Parse positional and keyword arguments */
    static char* keywords[] = { "obj", "number", NULL };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "Oi", keywords, &obj, &number)) {
        return NULL;
    }

    /* Function implementation starts here */

    if (number < 0) {
        PyErr_SetObject(PyExc_ValueError, obj);
        return NULL;    /* return NULL indicates error */
    }

    Py_RETURN_NONE;
}

/*
 * List of functions to add to MathPythonEM in exec_MathPythonEM().
 */
static PyMethodDef MathPythonEM_functions[] = {
    { "example", (PyCFunction)MathPythonEM_example, METH_VARARGS | METH_KEYWORDS, MathPythonEM_example_doc },
    { NULL, NULL, 0, NULL } /* marks end of array */
};

/*
 * Initialize MathPythonEM. May be called multiple times, so avoid
 * using static state.
 */
int exec_MathPythonEM(PyObject *module) {
    PyModule_AddFunctions(module, MathPythonEM_functions);

    PyModule_AddStringConstant(module, "__author__", "Administrator");
    PyModule_AddStringConstant(module, "__version__", "1.0.0");
    PyModule_AddIntConstant(module, "year", 2023);

    return 0; /* success */
}

/*
 * Documentation for MathPythonEM.
 */
PyDoc_STRVAR(MathPythonEM_doc, "The MathPythonEM module");


static PyModuleDef_Slot MathPythonEM_slots[] = {
    { Py_mod_exec, exec_MathPythonEM },
    { 0, NULL }
};

static PyModuleDef MathPythonEM_def = {
    PyModuleDef_HEAD_INIT,
    "MathPythonEM",
    MathPythonEM_doc,
    0,              /* m_size */
    NULL,           /* m_methods */
    MathPythonEM_slots,
    NULL,           /* m_traverse */
    NULL,           /* m_clear */
    NULL,           /* m_free */
};

PyMODINIT_FUNC PyInit_MathPythonEM() {
    return PyModuleDef_Init(&MathPythonEM_def);
}
