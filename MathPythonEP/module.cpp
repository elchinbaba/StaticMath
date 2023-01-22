#include <iostream>
#include <Matrix.h>
#include <Python.h>

using namespace MathLibrary;

void show_matrix(ROW n, COLUMN m, VALUE x)
{
	MATRIX matrix = Matrix(n, m);

	VECTOR_DOUBLE vector_m;
	for (int i = 0; i < matrix.getColumn(); i++)
	{
		vector_m.push_back(x);
	}

	ARRAY array_n;
	for (int i = 0; i < matrix.getRow(); i++)
	{
		array_n.push_back(vector_m);
	}

	matrix.setArray(array_n);

	std::cout << "Matrix:\n";
	matrix.show();
}

static PyObject* show_matrix_py(PyObject* /* unused module reference */, PyObject* o) {
	ROW row;
	COLUMN column;
	VALUE value;

	if (!PyArg_ParseTuple(o, "iid", &row, &column, &value)) {
		return NULL;
	}

	show_matrix(row, column, value);
}

static PyMethodDef mathpythonep_methods[] = {
	// The first property is the name exposed to Python, show_matrix
	// The second is the C++ function with the implementation
	// METH_O means it takes a single PyObject argument
	{ "show_matrix", (PyCFunction)show_matrix_py, METH_VARARGS, nullptr },

	// Terminate the array with an object containing nulls.
	{ nullptr, nullptr, 0, nullptr }
};

static PyModuleDef mathpythonep_module = {
	PyModuleDef_HEAD_INIT,
	"MathPythonEP",                        // Module name to use with Python import statements
	"Provides a function that shows the matrix",  // Module description
	0,
	mathpythonep_methods                   // Structure that defines the methods of the module
};

PyMODINIT_FUNC PyInit_MathPythonEP() {
	return PyModule_Create(&mathpythonep_module);
}